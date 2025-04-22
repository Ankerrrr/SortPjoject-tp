#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
#include <algorithm>
// move minimal to left
using namespace std;

unsigned long long int STLsort() {
  PROCESS_MEMORY_COUNTERS beforeMem, afterMem;
  GetProcessMemoryInfo(GetCurrentProcess(), &beforeMem, sizeof(beforeMem));
  unsigned long long int swapCounter = 0;
  cout << "SelectionSort, ";
  ofstream out;
  out.open("./sort/STL/out.txt");
  if (out.fail()) {
    cout << "Fail To Write on out.txt";
  }
  vector<int> a;
  readFile(a);

  sort(a.begin(), a.end());

  int count = outlf;
  for (int i = 0; i < a.size(); i++) {
    if (printOut)
      cout << a[i] << ",";
    out << a[i] << " ";
    if (count-- <= 0) {
      out << endl;
      count = outlf;
    }
  }
  // ���o����᪺�O����ϥΪ��A
  GetProcessMemoryInfo(GetCurrentProcess(), &afterMem, sizeof(afterMem));
  out.close();
  // �L�X�O�����T (KB)
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

// int main() {
//   selectionSort();
// }