#include <iostream>

#include "P01_Exceptions.hpp"
#include "P02_Exceptions_Handling.hpp"
#include "P03_Paper.hpp"
#include "P10_Writing_Utencils.hpp"
#include "P11_Pen.hpp"
#include "P12_Autopen.hpp"

using std::cout;
using std::endl;
using std::cin;

const string MSG_show_content = "Paper content is: ";
const string MSG_paper_amount = "Paper amount is: ";
const string MSG_ink_amount = "Ink amount is: ";

void yahoo(Writing_Utencils&, Paper&);
void shredder(Paper*);

Pen* getMeSomethingToWrite() { return new Pen; }

int main()
{
    try {
        Autopen autopen;

        cout << "Autopen writing example" << endl << endl;
        //�������� �������� ������� �� ���
        if ( !autopen.get_status() ) autopen.click();

        Paper* paper = NULL;
        try
        {
            paper = new Paper;

            autopen.write(paper, "Welcome home Bender!");
            cout << MSG_show_content << paper->get_content() << endl;
            cout << MSG_paper_amount << paper->get_paper_amount() << endl;
            cout << MSG_ink_amount << autopen.ink_amount << endl;

            delete paper;
        }
        catch(OutException& err)
        {
            //������������

            //� ������ �� ������, � ����� �� �����, ��� ��������
            //������ � ������ ��� �� �������������� ��������

            try
            {
                //� ��� �������������� ��������
                autopen.refill(10000000);
            }
            catch(...)
            {
                autopen.refill();
            }

            string msg = err.getBrokenMsg();
            unsigned maxSize = paper->get_paper_amount();
            for ( ; msg.size() > maxSize;  )
            {
                paper = new Paper; //��� ����� ������������ ������

                //������� ����� ���������� � ���������� �������
                string tempMsg = msg.substr(0, maxSize);

                //�������� ���
                msg.substr(maxSize, msg.size());

                //����� ���������� �����
                autopen.write(paper, tempMsg);

                delete paper; //�������� ���� ��� �� ����
                //��� ���������, �������� book.append(paper)
            }

            //��������
            if ( msg.size() )
            {
                paper = new Paper;
                autopen.write(paper, msg);
                delete paper;
            }
        }

        //��� ������ � ������������
        Writing_Utencils *wu = getMeSomethingToWrite();
        paper = new Paper;

        wu->write(paper, "Some text");

        delete wu;
        delete paper;
        //shredder(paper) �� ������� ��� ��� NULL, �� �� ���� ����� ������ �����������
        //� ��������� ������� "������ � ����������� ������"
        //paper->get_content();
        //��� ������ �����������  � ������������ ����������� ��������
        //��� ��� � �������������� � �������� �������� �� ����� ������������
        //� �� �� ����� �������(new) � ������������(shredder(paper))
    }
    catch(...)
    {
        return 1;
    }

    return 0;
}

void yahoo(Writing_Utencils& tool, Paper& paper) {
    //tool.write(paper, "Yahoo Google!");
    //cout << MSG_show_content << paper.get_content() << endl;
    //cout << MSG_paper_amount << paper.get_paper_amount() << endl;
}

void shredder(Paper* paper) {
    delete paper;
}
