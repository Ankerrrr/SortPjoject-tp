#include "./generateTestDat.hpp"
bool showConsole = false;

void generate(int testCase, int testRange) {
  ofstream out;
  out.open("./resource/dat.txt");

  if (out.fail()) {
    cout << "Fail to open file" << endl;
    exit(1);
  }
  cout << "Start Write Randon Number In File" << endl;
  srand((unsigned)time(NULL));

  int randonNumber;
  int showLoadingCut = testCase / 10;
  for (int i = 0; i < testCase; i++) {
    if (showLoadingCut % (i + 1) == 0) {
      cout << "--";
    }
    randonNumber = rand() % testRange + 1;
    if (showConsole) {
      cout << randonNumber << ", ";
    }
    out << randonNumber << " ";
  }
  out.close();
  cout << endl;
  cout << "Randon Number Generate Complete!!" << endl;
  cout << endl;
}