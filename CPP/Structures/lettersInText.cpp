#include <iostream>
#include <set>

using namespace std;

set<char> letterUnique(string text) {
    set<char>letters;
    
    for (int i = 0; text[i] != 0; i++) {
        if ( (text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122) ) {
            letters.insert(text[i]);
        }
    }
    
    return letters;
}

int main() {
    string text = "Trampam m pam tarPaMpAmTaRaMpAmPaRamiewrytpam 3473509695gmfskjhas3278crhygfdsdnbm ewrugyuy653985@$#%%$^#@$%$^ @%&@";
    
    set<char> letters = letterUnique(text);
    
    for ( set<char>::iterator it=letters.begin(); it != letters.end(); it++ ) {
        cout << *it << endl;
    }
    
    return 0;
}
