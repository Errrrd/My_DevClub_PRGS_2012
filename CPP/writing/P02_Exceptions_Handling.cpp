#include <iostream>
using std::cout;
using std::endl;
#include "P01_Exceptions.hpp"
#include "P02_Exceptions_Handling.hpp"

void exception_handling(IncorrectInkAmount& err) {
    cout << "Incorrect amount of ink, please try again" << endl;
}

void exception_handling(IncorrectPaperAmount& err) {
    cout << "Incorrect amount of paper, please try again" << endl;
}
/*
void exception_handling(OutOfInk& err) {
    Writing_Utencils* tool = err.get_tool();
    Paper* sheet = err.get_sheet();
    unsigned ink_shortage = err.get_ink_shortage();
    string initial_text = err.get_initial_text();

    cout << "Out of ink, refill/replace your pen" << endl;
    cout << "::DEBUG:: automatically refilling/replacing pen. We need " << ink_shortage << " of ink" << endl;

    tool->refill(ink_shortage);
    tool->write(*sheet, initial_text.substr(initial_text.length() - ink_shortage));
    cout << "Paper content is: " << sheet->get_content() << endl;
}

void exception_handling(OutOfPaper& err) {
    Writing_Utencils* tool = err.get_tool();
    Paper* sheet = err.get_sheet();
    unsigned paper_shortage = err.get_paper_shortage();
    string initial_text = err.get_initial_text();

    cout << "Out of paper, replace your paper" << endl;
    cout << "::DEBUG:: automatically replacing paper. We need " << paper_shortage << " of paper" << endl;

    cout << "Old paper content is: " << sheet->get_content() << endl;
    sheet->replace(paper_shortage);
    tool->write(*sheet, initial_text.substr(initial_text.length() - paper_shortage));
    cout << "New paper content is: " << sheet->get_content() << endl;
}*/

void exception_handling(ClosedAutopen& err) {
    cout << "Your autopen is closed, click it to write" << endl;
}
