#include <iostream>
#include <set>

#define DIFF 32

using namespace std;

set<string> wordUnique(string text) {
    string word;
    set<string>words;
    
    for (int i = 0; text[i] != 0; i++) {
        char symbol = text[i];
        
        if (symbol >= 65 && symbol <= 90) {
            symbol += DIFF;
        }
        if ( symbol >= 97 && symbol <= 122 ) {
            word.append(1, symbol);
        } else {
            if ( word != "" ) {
                words.insert(word);
            }
            word.clear();
        }
    }
    if ( word != "" ) {
        words.insert(word);
    }
    
    return words;
}

int main() {
    string text = "Trampam m pam  pam paM W w t GG gG Gg  tarPaMpAmTaRa MpAmPaRa MiewRryrtpam 3473509695gmfskjhas3278crhygfdsdnbm  ewr ugyuy65398 5@$#%%$^#@ $%$^ @%&@";
    
    set<string> word = wordUnique(text);
    
    for ( set<string>::iterator it=word.begin(); it != word.end(); it++ ) {
        cout << *it << endl;
    }
    
    return 0;
}
