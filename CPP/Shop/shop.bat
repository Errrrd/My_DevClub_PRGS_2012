g++ -c Category.cpp -o category.o
g++ -c item.cpp -o item.o
g++ -c order.cpp -o order.o
g++ -c customer.cpp -o customer.o
g++ -c shop.cpp -o shop.o
g++ category.o item.o order.o customer.o shop.o