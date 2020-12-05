class Point(object):
	def __init__(self, x, y):
		self.__x = int(x)
		self.__y = int(y)

	def __str__(self):
		# '%(language)s has %(#)03d quote types.' % \
  #         {'language': "Python", "#": 2}
		# return "(" + str(self.x) + ", " + str(self.y) + ")"
		# return "(%(x)g, %(y)g)" % {"y":self.y, "x":self.x}
		return '({}, {})'.format(self.__x, self.__y)
		# "The sum of 1 + 2 is {0}".format(1+2)

	def __eq__(self, other):
		print "lol"
		return self.__x == other.__x and self.__y == other.__y

	def __ne__(self, other):
		# return not self.__eq__(other)
		return not (self == other)


