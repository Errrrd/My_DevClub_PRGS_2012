#include<windows.h>
#include<iostream>
//#include <string.h>

using namespace std;

template<typename T>
int arrayScan(string str, T array[], int len) {
    int size = 0;
    
    for ( ; size < len && str[size]; size++ ) {
        array[size] = str[size];
    }
    array[size] = str[size];
    return size;
}

int main() {
    string dir = "ls -d ";
    string path;
    string at = "*";
    string str;
    char all[4000];
    
    
    
    cout << "vvedite polnyj put' (c:/dir1/dir2/.../)" << endl;
    cin >> path;
    
    str = dir + path + at;
    arrayScan(str, all, 4000);
    
    system(all);
    system("ls -l c:/*.*");
}
