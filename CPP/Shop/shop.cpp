// ��������� ��������

// ��������� ��� �����:

// Category 1 ------ * Item * ------ * Order * ------ 1 Customer

// Item: ������� ���������, ��������� ������ �������, ���������� � �������� ������. ����� ��� ��������� ������������ �� �����. 

// Order: ��������� �������, ��������� ������ �������, ����������/�������� ������. ������� �������� ������. ����� ��� ������� �� ����������, ��� �� ��������� � ��� �������.

// Customer: ��������� ���� �������, ���������� ������ ������.

// ��� ������� ������ ��������� ����� ��� ��������� ������� ������ ��������. ������������� �������� ������ ������� ��� ��������� ������ ����� ������. 
// ��������� ����������.
// ������, ��� ���� �� �� ������������� ���� ������, � ������� ������������ �������� ��� �� �����.

// ������ �� ������� �������. �� �������� �������. ����������� ������.
// �����: �������� ���������� �������������� ��� ������� ������.
// �����: ����������� ������������ ������������.

#include <iostream>

using namespace std;

#include "item.h"
#include "category.h"
#include "order.h"
#include "customer.h"

int main() {
    Category printers("printers");
    Category scanners("scanners");
    Category mfu("mfu");
    Category copiers("copiers");
    
    Item cannon1(printers, "Cannon1000", 110, 9);
    Item epson1(printers, "Epson100", 50, 10);
    Item hp1(printers, "HP1020", 100, 11);
    Item hp2(printers, "HP3020", 130, 12);
    Item hp3(scanners, "HPs1020", 60, 13);
    Item hp4(mfu, "HP5020", 150, 14);
    Item xerox1(copiers, "Xerox1020", 150, 16);
    
    Customer vasya("Vasya", 1000);
    Customer sasha("Sasha", 1000);
    Customer vanya("Vanya", 1000);
    
    Order vasyaOrd(vasya, hp2, 1);
    Order sashaOrd(sasha, cannon1, 5);
    Order vanyaOrd(vanya, hp1, 3);
        
    cout << "\nCategories - " << mfu.getCounter() << "\nitems - " << hp1.getCounter() << "\nCustomers - " 
    << sasha.getCounter() << "\nOrders - " << vasyaOrd.getCounter() << endl;
    
    hp2.changeCategory(mfu);
    
    cout << "\nhp2 - " << hp2.getCategory().getName() << endl;
    cout << "\nCategories - " << mfu.getCounter() << "\nitems - " << hp1.getCounter() << "\nCustomers - " 
    << sasha.getCounter() << "\nOrders - " << vasyaOrd.getCounter() << endl;
    
    return 0;
}