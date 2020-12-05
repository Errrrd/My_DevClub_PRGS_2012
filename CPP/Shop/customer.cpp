/*
Customer: получение всех заказов, добавление нового заказа.

Для каждого класса необходим метод для получения полного списка объектов. Необходимость создания нового объекта для получения списка будет фэйлом. 
Продумать исключения.
Учтите, что если вы не протестируете свои классы, с большой вероятностью работать они не будут.

Следим за именами методов. Не забываем геттеры. Продумываем логику.
Бонус: добавить уникальные идентификаторы для каждого класса.
Бонус: максимально использовать наследование.

        static unsigned int counter;
        unsigned int indifier;
        string name;
        set<Order*> listOrders;
        set<Customer*> customers;
        unsigned int many;
*/

#include "customer.h"

unsigned int Customer::counter = 0;

Customer::Customer(const string& name, unsigned int many = 0) : name(name), many(many) {
    counter += 1;
    this->indifier = counter;
    //customers.insert(this);
    cout << "Create Cust.\n";
}

Customer::~Customer(){
    //customers.erase(this);
    counter -= 1;
    //listOrders.~set();
    // if( this->counter == 0 ) {
        // delete &customers;
    // }
}

void Customer::addOrder(Order* order) {
    listOrders.insert(order);
    cout << "add CustOrd. ";
}

void Customer::removeOrder(Order* order) {
    if( listOrders.erase(order) == 0 ) {
        throw OrderNotFoundException();
    }
    delete order;
}

const set<Order*>& Customer::getListOrders() const {
    return listOrders;
}

// const set<Customer*>& Customer::getCustomers() const {
    // return customers;
// }

const string& Customer::getName() const {
    return name;
}

const unsigned int Customer::getCounter() const{
    return counter;
}

const unsigned int Customer::getIndifier() const {
    return indifier;
}

        