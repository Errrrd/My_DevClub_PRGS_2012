#include <dirent.h>
#include <stdio.h>
#include <iostream>

using namespace std;
 
int main () {
    DIR *dir;
    struct dirent *ent;
    char directory[4000];
    
    cout << "vvedite polnyj put' (c:/dir1/dir2/.../) or (./)" << endl;
    cin >> directory;
    
    //char directory[255] = "./";
    dir = opendir(directory);
    
    for ( ;(ent=readdir(dir)); ) {
        cout << ent->d_name << endl;
    }
    
    closedir(dir);
    
    return 0;
}