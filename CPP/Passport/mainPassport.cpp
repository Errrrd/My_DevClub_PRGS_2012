#include <iostream>

#include "Passport.h"

using namespace std;

int main() {
    string newSeries;
    Passport a;
    Passport b;
    
    Passport::setSeries("ad");
    
    Passport c;
    Passport d("Petro", "Sydorenco", 13, 1, 1965);
    Passport e("Sydor", "Petrenco", 22, 11, 1991);
    
    cout << "Set up pliz new series. Format: xx (2 letters): \n";
    cin >> newSeries;
    
    Passport::setSeries(newSeries);
    
    Passport f;
    Passport g;
    Passport h = d;
    
    cout << "a: \n" << a << "b: \n" << b << "c: \n" << c << "d: \n" << d << "e: \n" << e << "f: \n" << f << "g: \n" << g << "h: \n" << h <<endl;

   return 0;
}
