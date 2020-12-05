#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include "P03_Paper.hpp"
#include "P10_Writing_Utencils.hpp"

class IncorrectInkAmount {

private:
    unsigned ink_amount;

public:
    IncorrectInkAmount(unsigned amount) : ink_amount(amount) {}
    unsigned get_ink_amount() const { return ink_amount; }
};

class IncorrectPaperAmount {

private:
    unsigned paper_amount;

public:
    IncorrectPaperAmount(unsigned amount) : paper_amount(amount) {}
    unsigned get_paper_amount() const { return paper_amount; }
};

class OutException {

private:
    string m_what;
    string brokenMsg;  

public:
    OutException(const string& what, const string& brokenMsg) : m_what(what), brokenMsg(brokenMsg) {}

    const char* what() const throw() { return m_what.c_str(); }
    string getBrokenMsg() const { return brokenMsg; }
};


class ClosedAutopen {};

#endif
