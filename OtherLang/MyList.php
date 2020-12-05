<?php

ini_set('memory_limit', '-1');

$ls = array();
$loops = 5000000;

for ( $i = 0; $i < $loops; $i++ ) {
	$ls[] = $i;
}

readline();

?>