public class Natural {
	private static int loops = 2500000;

	public static void main(String[] args) throws Exception {
		StringBuilder output = new StringBuilder("1");

		for ( int i = 2; i <= loops; i++ ) {
			output.append(" " + i);
		}
		System.out.println(output);

		// System.in.read();
	}
}