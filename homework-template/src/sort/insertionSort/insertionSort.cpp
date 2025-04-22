// check from left to right
// if small then now check then move to left and check if small then left again
#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
using namespace std;

unsigned long long int inser() {
  PROCESS_MEMORY_COUNTERS beforeMem, afterMem;
  GetProcessMemoryInfo(GetCurrentProcess(), &beforeMem, sizeof(beforeMem));
  unsigned long long int swapCounter = 0;
  cout << "insertionSort, ";
  ofstream out;
  out.open("./sort/insertionSort/out.txt");
  if (out.fail()) {
    cout << "Fail To Write on out.txt";
    exit(1);
  }
  vector<int> a;
  readFile(a);

  // for (int i = 0; i < a.size(); i++) {
  //   cout << a[i] << ", ";
  // }
  // cout << endl;
  for (int i = 1; i < a.size(); i++) {
    int k = i;
    while (a[k - 1] > a[k] && k != 0) {
      int temp = a[k - 1];
      a[k - 1] = a[k];
      a[k] = temp;
      swapCounter++;
      k--;
    }
  }

  int count = outlf;
  for (int i = 0; i < a.size(); i++) {
    if (printOut)
      cout << a[i] << ", ";
    out << a[i] << " ";
    if (count-- <= 0) {
      out << endl;
      count = outlf;
    }
  }
  // 取得執行後的記憶體使用狀態
  GetProcessMemoryInfo(GetCurrentProcess(), &afterMem, sizeof(afterMem));
  // 印出記憶體資訊 (KB)
  cout << "----------------------" << endl;
  cout << "Memory Info (Before):" << endl;
  cout << "  Working Set Size:       " << beforeMem.WorkingSetSize / 1024 << " KB" << endl;
  cout << "  Peak Working Set Size:  " << beforeMem.PeakWorkingSetSize / 1024 << " KB" << endl;
  cout << "  Pagefile Usage:         " << beforeMem.PagefileUsage / 1024 << " KB" << endl;

  cout << "Memory Info (After):" << endl;
  cout << "  Working Set Size:       " << afterMem.WorkingSetSize / 1024 << " KB" << endl;
  cout << "  Peak Working Set Size:  " << afterMem.PeakWorkingSetSize / 1024 << " KB" << endl;
  cout << "  Pagefile Usage:         " << afterMem.PagefileUsage / 1024 << " KB" << endl;
  // cout << "  Working Set Diff:       " << memDiff / 1024 << " KB" << endl;
  cout << "----------------------" << endl;
  return swapCounter;
}
