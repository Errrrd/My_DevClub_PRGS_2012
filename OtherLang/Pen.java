public class Pen extends WritingUtencil {
	private int inkQuantity;

	public Pen(int ink) throws Throwable {
		if ( ink > 1000 || ink < 0 ) {
			throw new InvalidParam();
		}
		inkQuantity = ink;
	}

	public void write(Paper paper, String text) throws Throwable {
		if ( inkQuantity < text.length() ) {
			throw new OutOfInk();
		}
		paper.addContent(text);
	}
}