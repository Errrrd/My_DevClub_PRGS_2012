#include<windows.h>
#include<iostream>

using namespace std;

int main() {
    char dir[4000];
    
    
    cout << "vvedite polnyj put' (c:/dir1/dir2/.../) or (./)" << endl;
    cin >> dir;
    
    WIN32_FIND_DATA FindFileData;
    HANDLE hf;
    
    hf=FindFirstFile(dir, &FindFileData);
    if (hf!=INVALID_HANDLE_VALUE){
        do{
            std::cout << FindFileData.cFileName << "\n";
        }
        while (FindNextFile(hf,&FindFileData)!=0);
        FindClose(hf);
    }
}