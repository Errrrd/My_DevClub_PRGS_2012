/*
Category: ��������� ���� ������� � ���������, ���������� � �������� �������.

��� ������� ������ ��������� ����� ��� ��������� ������� ������ ��������. ������������� �������� ������ ������� ��� ��������� ������ ����� ������. 
��������� ����������.
������, ��� ���� �� �� ������������� ���� ������, � ������� ������������ �������� ��� �� �����.

������ �� ������� �������. �� �������� �������. ����������� ������.
�����: �������� ���������� �������������� ��� ������� ������.
�����: ����������� ������������ ������������.

        static unsigned int counter;
        unsigned int indifier;
		string name;
		set<Item*> listItems;
        set<Category*> categories;
*/

#include "category.h"

unsigned int Category::counter = 0;

Category::Category(const string& name) {
    counter += 1;
    indifier = counter;
    this->name = name;
    cout << "Create Cat.\n";
    //categories.insert(this);
}

Category::~Category() {
    //categories.erase(this);
    counter -= 1;
    for ( set<Item*>::iterator it = listItems.begin(); it != listItems.end(); it++ ) 
    {
        Item* item= *it;
        delete item;
    }
    //listItems.~set();
    // if( counter == 0 ) {
        // delete &categories;
    // }
}

void Category::addItem(Item* item) {
    listItems.insert(item);
    cout << "add Cat. ";
}

void Category::removeItem(Item* item) {
	if ( listItems.erase(item) == 0 ) {
		//throw ItemNotFoundException();
	}
}

const set<Item*>& Category::getListItems() const {
    return listItems;
}

// const set<Category*>& Category::getCategories() const {
    // return categories;
// }

const string& Category::getName() const {
    return name;
}

const unsigned int Category::getCounter() const {
    return counter;
}

const unsigned int Category::getIndifier() const {
    return indifier;
}
