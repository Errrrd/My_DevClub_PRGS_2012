/*
Order: получение клиента, получение списка товаров, добавление/удаление товара. Клиента изменить нельзя. Заказ без товаров не существует, как не существет и без клиента.

Для каждого класса необходим метод для получения полного списка объектов. Необходимость создания нового объекта для получения списка будет фэйлом. 
Продумать исключения.
Учтите, что если вы не протестируете свои классы, с большой вероятностью работать они не будут.

Следим за именами методов. Не забываем геттеры. Продумываем логику.
Бонус: добавить уникальные идентификаторы для каждого класса.
Бонус: максимально использовать наследование.

        static unsigned int counter;
        unsigned int number;
        Customer* customer;
        map<Item*, unsigned int> listOrderItems;
        static set<Order*> orders;
        unsigned int summPrice;
*/

#include "order.h"

unsigned int Order::counter = 0;
    
Order::Order(Customer& customer, Item& item, unsigned int needItem) : customer(&customer) {
    counter += 1;
    this->number = counter;
    this->summPrice = 0;
    addItem(&item, needItem);
    cout << "Create Ord.\n";
    //orders.insert(this);
}

Order::~Order() {
    //orders.erase(this);
    counter -= 1;
    //listOrderItems.~map();
    // if( this->counter == 0 ) {
        // delete &orders;
    // }
}

void Order::addItem(Item* item, unsigned int needItem) {
    unsigned int quantity = (*item).getQuantity();
    
    if( quantity < needItem ) {
        throw ItemNotInSightExeption();
    }
    listOrderItems[item] += needItem;
    (*item).changeQuantity(quantity - needItem);
    summPrice += needItem * (*item).getPrice();
    cout << "add It. ";
}

void Order::removeOrdersItem(Item* item) {
    unsigned int quantity = listOrderItems[item];

    if( listOrderItems.erase(item) == 0 ) {
        //throw ItemNotFoundException();
    }
    (*item).changeQuantity((*item).getQuantity() + quantity);
    summPrice -= quantity * (*item).getPrice();
}

const map<Item*, unsigned int>& Order::getListOrderItems() const {
    return listOrderItems;
}

// const set<Order*>& Order::getOrders() const {
    // return orders;
// }

const unsigned int Order::getCounter() const {
    return counter;
}

const unsigned int Order::getNumber() const {
    return number;
}

const unsigned int Order::getSummPrice() const {
    return summPrice;
}
