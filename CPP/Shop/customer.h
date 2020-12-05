/*
Customer: получение всех заказов, добавление нового заказа.

Для каждого класса необходим метод для получения полного списка объектов. Необходимость создания нового объекта для получения списка будет фэйлом. 
Продумать исключения.
Учтите, что если вы не протестируете свои классы, с большой вероятностью работать они не будут.

Следим за именами методов. Не забываем геттеры. Продумываем логику.
Бонус: добавить уникальные идентификаторы для каждого класса.
Бонус: максимально использовать наследование.
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <set>

#include "order.h"
#include "item.h"
#include "exceptions.h"

using namespace std;

class Order;

class Customer {
    private:
        static unsigned int counter;
        unsigned int indifier;
        string name;
        set<Order*> listOrders;
        unsigned int many;
        //static set<Customer*> customers;
    
    public:
        Customer(const string&, unsigned int);
    
        ~Customer();
        
        void addOrder(Order* order);

		void removeOrder(Order* order);

		const set<Order*>& getListOrders() const;
        
        // const set<Customer*>& getCustomers() const;
        
		const string& getName() const;
        
        const unsigned int getCounter() const;
        
        const unsigned int getIndifier() const;
};

#endif
