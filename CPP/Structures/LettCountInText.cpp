#include <iostream>
#include <map>

using namespace std;

map<char, int> letterUnique(string text) {
    map<char, int>letters;
    
    for (int i = 0; text[i] != 0; i++) {
        if ( (text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122) ) {
            letters[text[i]] += 1;
        }
    }
    
    return letters;
}

int main() {
    string text = "Trampam m pam tarPaMpAmTaRaMpAmPaRaMiewRryrtpam 3473509695gmfskjhas3278crhygfdsdnbm ewrugyuy653985@$#%%$^#@$%$^ @%&@";
    
    map<char, int> letters = letterUnique(text);
    
for (map<char,int>::iterator  it=letters.begin() ; it != letters.end(); it++ ) {
    cout << (*it).first << " = " << (*it).second << endl;
}
    
    return 0;
}
