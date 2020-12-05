#ifndef PAPER_HPP
#define PAPER_HPP

#include <string>
#include "WritingUtencil.hpp"

using namespace std;

class Paper {
	private:
		string* content;

	public:
		Paper() : content(new string) {}

		virtual ~Paper() { delete content; }

		virtual const string& getContent() const;

		virtual void show() const;

		virtual void addContent(const string& text);
};

#endif
