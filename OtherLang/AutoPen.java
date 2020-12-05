public class AutoPen extends Pen {
	private boolean isOpen = false;

	public AutoPen(int ink) throws Throwable {
		super(ink);
	}

	public void write(Paper paper, String text) throws Throwable {
		if ( !isOpen ) {
			throw new ClosedPen();
		}
		super.write(paper, text);
	}
}