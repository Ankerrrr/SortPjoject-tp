#include "ReadFile.hpp"
using namespace std;

void readFile(vector<int> &r) {
  ifstream in("C:/Users/A9403/Document/School/dataStruct2/3_20/resource/dat.txt");

  if (in.fail()) {
    cout << "Fali to loading IN file" << endl;
    exit(1);
  }

  int value;
  while (in >> value) {
    if (in.fail()) {
      break;
    }
    r.push_back(value);
  }
  in.close();
}