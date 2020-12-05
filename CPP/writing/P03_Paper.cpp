#include "P01_Exceptions.hpp"
#include "P02_Exceptions_Handling.hpp"
#include "P03_Paper.hpp"

Paper::Paper() : paper_amount(50) {}

Paper::Paper(unsigned paper)
{
    //Критично!
	if( paper > max_paper_capacity ) throw IncorrectPaperAmount(paper);
	
	paper_amount = paper;
}

Paper::~Paper() {}

void Paper::replace(const unsigned paper)
{
	if ( paper > max_paper_capacity )
	{
		//Критично? : throw IncorrectPaperAmount(paper);
        //Не критично?:  cout << "warning" << endl;
	}
    
	paper_amount = paper;
    content = "";
}
