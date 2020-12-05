#include "P01_Exceptions.hpp"
#include "P12_Autopen.hpp"

Autopen::Autopen() : open(false) {}

Autopen::Autopen(unsigned ink) : Pen(ink), open(false) {}

Autopen::~Autopen() {}

void Autopen::write(Paper *paper, const string& text)
{
    if ( open ) Pen::write(paper, text);
    //Не критично!
    //else cout << "Pen is closed" << endl;
}
