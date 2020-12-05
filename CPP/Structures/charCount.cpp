// Создать мапу символов по задаче чаркаут
//взять Си код
//заменить массив на "мап" и вывести в файл
#include <iostream>
#include <map>

using namespace std;

void charCount(string strinG) {
    map<char,int>quantity;
    
    for (int i = 0; strinG[i] != 0; i++) {
        quantity[strinG[i]] += 1;
    }
    
    for ( map<char,int> :: iterator it = quantity.begin(); it != quantity.end(); it++ ) {
        cout << (*it).first << ' ' <<(*it).second << endl;
    }
}

int main() {
    
    string strinG = "Tramtara  mTADAMpaM vcPAm!@!$% $#%$^*&$@!$5g 676656584263";
    
    charCount(strinG);
    
    return 0;
}
