import java.util.ArrayList;

public class MyList {
	private static int loops = 5000000;

	public static void main(String[] args) throws Throwable {
		ArrayList<Integer> ls = new ArrayList<Integer>();
		for ( int i = 0; i < loops; i++ ) {
			ls.add(i);
		}

		System.in.read();
	}
}