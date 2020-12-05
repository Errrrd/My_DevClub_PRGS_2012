/*
Item: ������� ���������, ��������� ������ �������, ���������� � �������� ������. ����� ��� ��������� ������������ �� �����.

��� ������� ������ ��������� ����� ��� ��������� ������� ������ ��������. ������������� �������� ������ ������� ��� ��������� ������ ����� ������. 
��������� ����������.
������, ��� ���� �� �� ������������� ���� ������, � ������� ������������ �������� ��� �� �����.

������ �� ������� �������. �� �������� �������. ����������� ������.
�����: �������� ���������� �������������� ��� ������� ������.
�����: ����������� ������������ ������������.

        static unsigned int counter;
        unsigned int indifier;
        Category category;
        set<Order*> listOrders;
        set<Item*> items;
        string name;
        unsigned int price;
        unsigned int quantity;
        
*/

#include "item.h"

unsigned int Item::counter = 0;

Item::Item(Category& category, const string& name, unsigned int price, unsigned int quantity ) {
    counter += 1;
    this->indifier = counter;
    this->category = &category;
    this->name = name;
    this->price = price;
    this->quantity = quantity;
    cout << "Create It.\n";
    //items.insert(this);
}

Item::~Item() {
    //items.erase(this);
    counter -= 1;
    this->category->removeItem(this);
    for ( set<Order*>::iterator it = listOrders.begin(); it != listOrders.end(); it++ ) {
        (*it)->removeOrdersItem(this);
    }
    //listOrders.~set();
    // if( counter == 0 ) {
        // delete &items;
    // }
}

void Item::changeCategory(Category& newCategory) {
    if ( !newCategory.getListItems().empty() ) {
        category->removeItem(this);
    }
    newCategory.addItem(this);
    *category = newCategory;
    cout << "change Cat. ";
}

void Item::addOrder(Order* order) {
    listOrders.insert(order);
    cout << "add Ord. ";
}

void Item::removeOrder(Order* order) {
    if ( listOrders.erase(order) == 0 ) {
		throw OrderNotFoundException();
	}
}

const set<Order*>& Item::getListOrders() const {
    return listOrders;
}

// const set<Item*>& Item::getItems() const {
    // return items;
// }

const string& Item::getName() const {
    return name;
}

const unsigned int Item::getPrice() const {
    return price;
}

void Item::changePrice(unsigned int price) {
    this->price = price;
}

const unsigned int Item::getQuantity() const {
    return quantity;
}
void Item::changeQuantity(unsigned int quantity) {
    this->quantity = quantity;
}

const unsigned int Item::getCounter() const {
    return counter;
}

const unsigned int Item::getIndifier() const {
    return indifier;
}

const Category& Item::getCategory() const {
    return *category;
}
