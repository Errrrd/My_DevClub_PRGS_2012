/*
Category: ��������� ���� ������� � ���������, ���������� � �������� �������.

��� ������� ������ ��������� ����� ��� ��������� ������� ������ ��������. ������������� �������� ������ ������� ��� ��������� ������ ����� ������. 
��������� ����������.
������, ��� ���� �� �� ������������� ���� ������, � ������� ������������ �������� ��� �� �����.

������ �� ������� �������. �� �������� �������. ����������� ������.
�����: �������� ���������� �������������� ��� ������� ������.
�����: ����������� ������������ ������������.
*/

#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <set>

#include "item.h"
#include "exceptions.h"

using namespace std;

class Item;

class Category {
    private:
        static unsigned int counter;
        unsigned int indifier;
		string name;
		set<Item*> listItems;
        //static set<Category*> categories;
    
    public:
        Category(const string&);
        
        ~Category();
        
        void addItem(Item*);

		void removeItem(Item*);

		const set<Item*>& getListItems() const;
        
        // const set<Category*>& getCategories() const;
        
		const string& getName() const;
        
        const unsigned int getCounter() const;
        
        const unsigned int getIndifier() const;
};

#endif
