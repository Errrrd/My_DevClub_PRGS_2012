#ifndef AUTOPEN_HPP
#define AUTOPEN_HPP

#include "P11_Pen.hpp"

class Autopen : public Pen {

private:
    bool open;

public:
    Autopen();
    Autopen(unsigned);
    virtual ~Autopen();

    virtual void write(Paper* paper, const string&);

    void click() { open = !open; }
    bool get_status() const { return open; }
};

#endif
