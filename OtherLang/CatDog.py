class Cat(object):
	def meow(self):
		print "meow"
	def walk(self):
		print "{} walks alone".format(self.__class__.__name__)

class Dog(object):
	def bark(self):
		print "grrr!"
	def walk(self):
		print "{} walks with it's master".format(self.__class__.__name__)

class CatDog(Cat, Dog):
	def walk(self):
		# super(Cat).walk()
		Cat.walk(self)
		Dog.walk(self)

cd = CatDog()

cd.meow()
cd.bark()

# cd.walk()

Cat.walk(cd)

