#ifndef PEN_HPP
#define PEN_HPP

#include "P10_Writing_Utencils.hpp"

class Pen : public Writing_Utencils {

private:
    static const unsigned max_ink_capacity = 100;

public:
    Pen();
    Pen(unsigned ink);
    virtual ~Pen();

    virtual void write(Paper *paper, const string& text);
    virtual void refill(const unsigned = max_ink_capacity);

    unsigned ink_amount;
};

#endif
