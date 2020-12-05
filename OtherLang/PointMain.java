public class PointMain {
	public static void main(String[] args) {
		Point a = new Point(3, 4);
		Point b = new Point();

		System.out.println("distance: " + a.getDistance(b));
		System.out.print(a);

		if ( a.equals(b) ) {
			System.out.print(" equals ");
		} else {
			System.out.print(" not equal ");
		}

		a = Null;
		
		System.out.println(b);		
	}
}