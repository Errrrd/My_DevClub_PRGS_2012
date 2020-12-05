#ifndef AUTOPEN_CPP
#define AUTOPEN_CPP

#include "Pen.cpp"

class AutoPen : public Pen {
	private:
		bool open;

	public:
		AutoPen(int amount = 100) : Pen(amount), open(false) {}

		bool isOpen() const { return open; }

		void click() { open = !open; }

		virtual void write(Paper& paper, const string& text) {
			#ifdef DEBUG
				cout << "AutoPen writing..." << endl;
			#endif

			if ( open ) {
				Pen::write(paper, text);
			}
		}
};

#endif
