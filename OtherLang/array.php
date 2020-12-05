<?php

class Test {}

$t = new Test();

// $a = array(1, 2, "lol", 4, array(8, 10, 15), $a);

// // $a[] = 42;
// // $a[] = &$a;

// $a[42] = "blah";
// $a[] = "chto-to";

// $a["kwefgkjqwebf"] = 0;

// $a[35] = 35;
// $a[] = 73;
// $a[35] = 105;
// $a[] = $t;
// $a[] = $t;
// $a[] = new Test();
$a = array();
// $a[$t] = 42;

$t2 = clone $t;

var_dump($a);
var_dump($t);
var_dump($t2);

?>