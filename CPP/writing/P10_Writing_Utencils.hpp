#ifndef WRITING_UTENCILS_HPP
#define WRITING_UTENCILS_HPP

#include "P03_Paper.hpp"

class Writing_Utencils {

public:
    virtual ~Writing_Utencils() {}
    virtual void write(Paper *paper, const string& text);
    virtual void refill(const unsigned) = 0;
};

inline void Writing_Utencils::write(Paper *paper, const string& text)
{
    paper->add_content(text);
    paper->set_paper_amount(paper->get_paper_amount() - text.length());
}

#endif
