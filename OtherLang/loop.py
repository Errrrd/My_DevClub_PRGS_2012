def main():
	loops = 10000000
	counter = 0

	for i in xrange(loops):
		if i % 2 == 0:
			counter += 1
		else:
			counter -= 1		

	print counter

main()
