#ifndef WRITING_UTENCIL_HPP
#define WRITING_UTENCIL_HPP

#include <string>

#include "Paper.hpp"

class Paper;

class WritingUtencil {
	public:
		virtual void write(Paper&, const std::string&) = 0;
};

#endif
