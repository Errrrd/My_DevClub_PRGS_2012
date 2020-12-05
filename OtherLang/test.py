def blah(arg = None):
	if arg == None: return 0

	return int(arg)

print blah()
print blah(42)
print blah("42")
print blah('42')
print blah(42.0)

print blah(42.4);
print blah("42.4");
print blah("42lgn");
print blah("lol");
# print blah(array());
# print blah(array(88));
# print blah(new Test1());
# print blah(new Test2());
# print blah(true);
# print blah(false);
