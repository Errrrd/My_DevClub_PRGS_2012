<?php

class Test1 {}

class Test2 {
	public function __toString() {
		return "42";
	}
}

function blah($arg = null) {
	$test = intval($arg);
	throw new Test1();
	if ( is_null($arg) || is_numeric($arg) && $test == $arg ) {
		print "$arg is number\n";
	} else {
		print "$test is not a number\n";
	}
}

echo blah();
echo blah(42);
echo blah("42");
echo blah('42');

echo blah(42.4);
echo blah("42.4");
echo blah("42lgn");
echo blah("lol");
echo blah(array());
echo blah(array(88));
echo blah(new Test1());
echo blah(new Test2());
echo blah(true);
echo blah(false);

?>