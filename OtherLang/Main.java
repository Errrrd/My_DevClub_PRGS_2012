public class Main {
	public static void main(String[] args) throws Exception {
		WritingUtencil pen = new Pen(100);
		Paper paper = new Paper();

		pen.write(paper, "Hello world!");

		paper.show();
	}
}