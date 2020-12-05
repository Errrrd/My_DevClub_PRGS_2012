public class Loop {
	public static int loops = 100000000;

	public static void main(String[] args) {
		int counter = 0;

		for ( int i = 0; i < loops; i++ ) {
			if ( i % 2 == 1 ) {
				counter += 1;
			} else {
				counter -= 1;
			}
		}

		System.out.println(counter);
	}
}
