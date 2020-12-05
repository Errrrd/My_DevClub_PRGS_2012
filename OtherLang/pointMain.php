<?php

include("Point.php");

$a = new Point(3, 4);
$b = new Point();

echo $a;

if ( $a == $b ) {
	echo " equals ";
} else {
	echo " not equal ";
}

echo $b . "\n";

?>