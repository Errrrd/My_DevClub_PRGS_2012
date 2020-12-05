#ifndef PAPER_HPP
#define PAPER_HPP

#include <string>

using std::string;

class Paper {

private:
    static const unsigned max_paper_capacity = 750;
    unsigned paper_amount;
    string content;
		
public:
    Paper();
    Paper(unsigned);
    virtual ~Paper();
		
    virtual string& get_content() { return content; }
    virtual void add_content(const string& text) { content += text; }
		
    virtual void replace(const unsigned);
		
    unsigned get_paper_amount() const { return paper_amount; }
    void set_paper_amount(const unsigned paper) { paper_amount = paper; }
};

#endif
