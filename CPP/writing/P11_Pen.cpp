#include "P01_Exceptions.hpp"
#include "P02_Exceptions_Handling.hpp"
#include "P11_Pen.hpp"

Pen::Pen() : ink_amount(max_ink_capacity) {}

Pen::Pen(unsigned ink)
{
    //Критично!
    if ( ink > max_ink_capacity ) throw IncorrectInkAmount(ink);

    ink_amount = ink;
}

Pen::~Pen() {}

void Pen::write(Paper *paper, const string& text)
{
    if ( !paper )
    {
        //Только предупреждение
        //cout << "Accert! Paper is null ptr" << endl;
    }

    unsigned paper_amount = paper->get_paper_amount();
    unsigned text_length = text.length();

    string written_text;

    if ( ink_amount >= text_length && paper_amount >= text_length )
    {
        Writing_Utencils::write(paper, text);
        ink_amount -= text_length;

    }
    else
    {
        if ( ink_amount < paper_amount )
        {
            //unsigned ink_shortage = text_length - ink_amount;
            written_text = text.substr(0, ink_amount);
            string brokenText = text.substr(ink_amount, text.size());

            Writing_Utencils::write(paper, written_text);
            ink_amount = 0;
            //Критично!
            throw OutException("Out of pen ink", brokenText);
        }
        else
        {
            //unsigned paper_shortage = text_length - paper_amount;
            written_text = text.substr(0, paper_amount);
            string brokenText = text.substr(paper_amount, text.size());

            Writing_Utencils::write(paper, written_text);
            ink_amount -= written_text.length();
            //Критично!
            throw OutException("Out of paper", brokenText);
        }
    }
}

void Pen::refill(const unsigned ink)
{
    //Критично!
    if ( ink > max_ink_capacity ) throw IncorrectInkAmount(ink);

    ink_amount = ink;
}
