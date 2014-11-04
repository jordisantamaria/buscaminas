import random

class Casella(object):
	__slots__ = ['__nMinasProp', '__destapat', '__interrogant', '__bandera']
	def __init__(self):
		self.__nMinasProp = 0
		self.__destapat = False
		self.__bandera = False
		self.__interrogant = False
	def setnMinasProp(self, num): self.__nMinasProp = num
	def getnMinasProp(self): return self.__nMinasProp

	def setDestapat(self, destapat): self.__destapat = destapat
	def getDestapat(self): return self.__destapat

	def setInterrogant(self, interrogant): self.__interrogant = interrogant
	def getInterrogant(self): return self.__interrogant

	def setBandera(self, bandera): self.__bandera = bandera
	def getBandera(self): return self.__bandera
	def __str__(self):
		return str(self.getnMinasProp())

MINA = 9
CASELLA_SENSE_DESTAPAR = 178
WIN = 4

class Tabler(object):
	
	__slots__ = ['__width', '__height', '__minas', 'casellas', '__minasRestants', '__punts','__turn']
	def __init__(self, width = 9, height = 9, minas = 10):
		self.__width = width
		self.__height = height
		self.__minas = minas
		self.__minasRestants = minas
		self.__punts = 0
		self.__turn = 1
		self.casellas = [[0 for x in xrange(width)] for x in xrange(height)] 
		for i in range(width):
			for j in range(height):
				self.casellas[i][j] = Casella()
				#print self.casellas[i][j].getnMinasProp()
		self.inicialitzarMinas()
		self.inicialitzarnumMinasAdjacents()

	def setWidth(self, w): self.__width = w
	def getWidth(self): return self.__width

	def setHeight(self, h): self.__height = h
	def getHeight(self): return self.__height

	def setMinas(self, minas): self.__minas = minas
	def getMinas(self): return self.__minas

	def inicialitzarMinas(self):
		numMinas = 0
		while numMinas < self.__minas:
			randX = self.__numAleatori(self.__width-1)
			randY = self.__numAleatori(self.__height-1)
			if self.casellas[randX][randY].getnMinasProp() ==0:
				self.casellas[randX][randY].setnMinasProp(MINA)
				
				numMinas= numMinas+1



	def inicialitzarnumMinasAdjacents(self):
		numero = 0
		for i in range(self.__width):
			for j in range(self.__height):
				if self.casellas[i][j].getnMinasProp() == 0:
					numero = self.__setNumMinas(i,j)
					self.casellas[i][j].setnMinasProp(numero)
	def __setNumMinas(self, x,y):
		numMinasAdjacents = 0
		i = self.__min(x-1, 0)
		j = self.__min(y-1, 0)

		for i in range(i, x+2):
			for j in range(j, y+2):
				if i>0 and i < self.__width and j>=0 and j<self.__height:
					if self.casellas[i][j].getnMinasProp() == MINA:
						numMinasAdjacents+=1
		return numMinasAdjacents

	def __min(self, num, min):
		if num < min:
			return min
		else:
			return num
	def __max(self, num, max):
		if num > max:
			return max
		else:
			return num

	def __numAleatori(self, maxnum):
		return random.randrange(maxnum)

	def draw(self):
		c = chr(CASELLA_SENSE_DESTAPAR)
		i = 0
		j = 0
		fila = [0,0,0,0,0,0,0,0,0]
		"""while j<self.__height:
			#if self.casellas[i][j].getDestapat() == False:
			#	print c
			#else:
			#print self.casellas[i][j].getnMinasProp()
			
			fila[i] = self.casellas[i][j].getnMinasProp()
			print fila
			i+=1
			if i==self.__width-1:
				i=0
				j+=1
				print '\n'"""
		
		for i in range(self.__width):
			for j in range(self.__height):
				fila[j] = self.casellas[i][j].getnMinasProp()

			print fila
		def demanarMoviment(self, estat):
			if self.__minasRestants == 0:
				self.__punts = self.__turn
				estat = WIN
				print "Quin moviment vols fer ?" 
				print "1. Destapar casella"  
				print "2. Colocar Bandera" 
				print "3. Posar Interrogant"  

				opcio = raw_input()

				if opcio == 1:
					self.__moviment()
				elif opcio == 2:
					self.__demanarBandera()
				elif opcio == 3:
					self.__demanarInterrogant()
				else:
					self.demanarMoviment(estat)
		def __demanarInterrogant(self):
			x = self.__demanarCoordenadaX()
			y = self.__demanarCoordenadaY()
			self.casellas[x-1][y-1].setInterrogant(True)
			print "La CASELLA " + str(x) + str(y) + "te interrogant"
		def __demanarBandera(self):
			x = self.__demanarCoordenadaX()
			y = self.__demanarCoordenadaY()
			if self.casellas[x-1][y-1].getnMinasProp() == MINA and casella[x-1][y-1].getBandera() == False:
				self.casellas[x-1][y-1].setBandera(True)
				minasRestants-=1
		#def __moviment():



		def __demanarCoordenadaX(self):
			x = int(raw_input('Coordenada X: '))
			if x < 0 or x>=width:
				print 'Coordenada Incorrecte'
				x = self.__demanarCoordenadaX()
			return x
		def __demanarCoordenadaY(self):
			y = int(raw_input('Coordenada Y: '))
			if y < 0 or y>height:
				print 'Coordenada Incorrecte'
				y = self.__demanarCoordenadaY()
			return y
