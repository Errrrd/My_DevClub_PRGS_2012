/*
Item: задания категории, получение списка заказов, добавление и удаление заказа. Товар без категории существовать не может.

Для каждого класса необходим метод для получения полного списка объектов. Необходимость создания нового объекта для получения списка будет фэйлом. 
Продумать исключения.
Учтите, что если вы не протестируете свои классы, с большой вероятностью работать они не будут.

Следим за именами методов. Не забываем геттеры. Продумываем логику.
Бонус: добавить уникальные идентификаторы для каждого класса.
Бонус: максимально использовать наследование.
*/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <set>

#include "category.h"
#include "order.h"
#include "exceptions.h"

using namespace std;

class Category;
class Order;

class Item {
    private:
        static unsigned int counter;
        unsigned int indifier;
        Category* category;
        set<Order*> listOrders;
        string name;
        unsigned int price;
        unsigned int quantity;
        //static set<Item*> items;
    
    public:
        Item(Category&, const string&, unsigned int, unsigned int);
        
        ~Item();
        
        void changeCategory(Category&);
        
        void addOrder(Order*);
        
		void removeOrder(Order*);
        
		const set<Order*>& getListOrders() const;
        
        // const set<Item*>& getItems() const;
        
		const string& getName() const;
        
        const unsigned int getPrice() const;
        
        void changePrice(unsigned int);
        
        const unsigned int getQuantity() const;
        
        void changeQuantity(unsigned int);
        
        const unsigned int getCounter() const;
        
        const unsigned int getIndifier() const;
        
        const Category& getCategory() const;
};

#endif
