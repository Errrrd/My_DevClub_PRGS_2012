<?php

$loops = 10000000;
$counter = 0;

for ( $i = 0; $i < $loops; $i++ ) {
	if ( $i % 2 != 0 ) {
		$counter += 1;
	} else {
		$counter -= 1;
	}
}

echo $counter;

?>