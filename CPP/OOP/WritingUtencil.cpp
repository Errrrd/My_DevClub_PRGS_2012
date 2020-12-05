#include <string>

#include "WritingUtencil.hpp"
#include "Paper.hpp"

class Paper;

void WritingUtencil::write(Paper& paper, const std::string& text) {
	paper.addContent(text);
}
