class Paper {
	private StringBuilder content = new StringBuilder();

	public void addContent(String text) {
		content.append(text);
	}

	public void show() {
		System.out.println(content);
	}
}