#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
// move minimal to left
using namespace std;

unsigned long long int selectionSort() {
  PROCESS_MEMORY_COUNTERS beforeMem, afterMem;
  GetProcessMemoryInfo(GetCurrentProcess(), &beforeMem, sizeof(beforeMem));
  unsigned long long int swapCounter = 0;
  cout << "SelectionSort, ";
  ofstream out;
  out.open("./sort/selectionSort/out.txt");
  if (out.fail()) {
    cout << "Fail To Write on out.txt";
  }
  vector<int> a;
  readFile(a);
  // for (int i = 0; i < a.size(); i++) {
  //   cout << a[i] << ",";
  // }
  // cout << endl;
  for (int i = 0; i < a.size(); i++) {
    int min = a[i];
    for (int j = i; j < a.size(); j++) {
      if (a[j] < min) {
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
        min = a[i];
        swapCounter++;
      }
    }
  }
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
  // 取得執行後的記憶體使用狀態
  GetProcessMemoryInfo(GetCurrentProcess(), &afterMem, sizeof(afterMem));
  out.close();
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

// int main() {
//   selectionSort();
// }