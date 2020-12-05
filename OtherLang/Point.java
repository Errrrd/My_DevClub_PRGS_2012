public class Point {
	private double x = 0;
	private double y = 0;

	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public Point() {}

	public double getX() {
		return x;
	}

	public double getY() {
		return y;
	}

	public boolean equals(Point other) {
		return x == other.x && y == other.y;
	}

	public double getDistance(Point other) {
		return Math.hypot(x-other.x, y-other.y);
	}

	public String toString() {
		return "(" + x + ", " + y + ")";
	}
}
