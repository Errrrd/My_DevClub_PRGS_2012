/*
 Order: получение клиента, получение списка товаров, добавление/удаление товара. Клиента изменить нельзя. Заказ без товаров не существует, как не существет и без клиента.

Для каждого класса необходим метод для получения полного списка объектов. Необходимость создания нового объекта для получения списка будет фэйлом. 
Продумать исключения.
Учтите, что если вы не протестируете свои классы, с большой вероятностью работать они не будут.

Следим за именами методов. Не забываем геттеры. Продумываем логику.
Бонус: добавить уникальные идентификаторы для каждого класса.
Бонус: максимально использовать наследование.
*/

#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <map>
#include <set>

#include "customer.h"
#include "item.h"
#include "exceptions.h"

using namespace std;

class Customer;
class Item;

class Order {
    private:
        static unsigned int counter;
        unsigned int number;
        Customer* customer;
        map<Item*, unsigned int> listOrderItems;
        unsigned int summPrice;
        //static set<Order*> orders;
    
    public:
        Order(Customer&, Item&, unsigned int);
        
        ~Order();
        
        void addCustomer(Customer*);
        
        void addItem(Item*, unsigned int);

		void removeOrdersItem(Item*);

		const map<Item*, unsigned int>& getListOrderItems() const;
        
        // const  set<Order*>& getOrders() const;

		const unsigned int getCounter() const;
        
        const unsigned int getNumber() const;
        
        const unsigned int getSummPrice() const;
};

#endif
