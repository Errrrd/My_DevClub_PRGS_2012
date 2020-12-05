<?php

class Point {
	private $x;
	private $y;

	public function __construct($x = 0, $y = 0) {
		$this->x = $x;
		$this->y = $y;
	}

	public function getX() {
		return $this->x;
	}

	public function getY() {
		return $this->y;
	}

	public function getDistance(Point $other) {
		$deltaX = $this->x - $other->x;
		$deltaY = $this->y - $other->y;

		return hypot($deltaX, $deltaY);
	}

	public function __toString() {
		return "($this->x, $this->y)";
	}
}
?>
