#include <iostream>
#include <fstream>
using namespace std;

int main() {

  ifstream infile;

  infile.open("task.in", ifstream::in);

  int ch = infile.get();
  while (infile.good()) {
    cout << (char) ch;
    ch = infile.get();
  }

  infile.close();

  return 0;
}
