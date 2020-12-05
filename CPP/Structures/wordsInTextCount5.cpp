#include <iostream>
#include <map>

using namespace std;

map<string, int> wordUnique(string text) {
    string word;
    map<string, int>words;
    
    for (int i = 0; text[i] != 0; i++) {
        char symbol = text[i];
        
        if ( (symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122) ) {
            word.append(1, symbol);
        } else {
            if ( word != "" ) {
                words[word] += 1;
            }
            word.clear();
        }
    }
    if ( word != "" ) {
        words[word] += 1;
    }
    
    return words;
}

int main() {
    string text = "Trampam m pam W      pam paM W w t GG gG Gg  tarPaMpAmTaRa MpAmPaRa MiewRryrtpam 3473509695gmfskjhas3278crhygfdsdnbm  ewr ugyuy65398 5@$#%%$^#@ $%$^ @%&@";
    
    map<string, int> words = wordUnique(text);
    
    for (map<string,int>::iterator  it=words.begin() ; it != words.end(); it++ ) {
        cout << (*it).first << " = " << (*it).second << endl;
    }
    
    return 0;
}
