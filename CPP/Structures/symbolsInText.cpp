#include <iostream>
#include <set>

using namespace std;

set<char> symbolUnique(string text) {
    set<char>symbols;
    
    for (int i = 0; text[i] != 0; i++) {
        symbols.insert(text[i]);
    }
    
    return symbols;
}

int main() {
    string text = "Trampam m pam tarPaMpAmTaRaMpAmPaRamiewrytpam 3473509695gmfskjhas3278crhygfdsdnbm ewrugyuy653985@$#%%$^#@$%$^ @%&@";
    
    set<char> symbols = symbolUnique(text);
    
    for ( set<char>::iterator it=symbols.begin(); it != symbols.end(); it++ ) {
        cout << *it << endl;
    }
    
    return 0;
}
