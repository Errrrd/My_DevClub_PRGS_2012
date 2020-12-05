#ifndef DOUBLE_PAPER_CPP
#define DOUBLE_PAPER_CPP

#include "Paper.cpp"

class DoublePaper : public Paper {
	private:
		string* content2;

	public:
		DoublePaper() {
			content2 = new string;
		}

		~DoublePaper() {
			cout << "Destructing DoublePaper...." << endl;
			delete content2;
		}

		const string& getContent() const {
			return *content2;
		}

		void show() const {
			cout << *content2 << endl;
		}

		void addContent(const string& text) {
			*content2 += text;
		}
};

#endif