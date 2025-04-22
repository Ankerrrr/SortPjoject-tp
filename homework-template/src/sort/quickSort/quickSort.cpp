#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
using namespace std;

int partition(vector<int> &arr, int lo, int hi, unsigned long long int &swapCounter) {
  int pivotIndex = (hi + lo) / 2;

  swap(arr[pivotIndex], arr[hi]);
  int i = lo - 1;
  for (int j = lo; j < hi; j++) {
    if (arr[j] < arr[hi]) {
      i++;
      swap(arr[i], arr[j]);
      swapCounter++;
    }
  }
  swap(arr[i + 1], arr[hi]);
  swapCounter++;
  return i + 1;
}

// int partition(vector<int> &arr, int lo, int hi, unsigned long long int &swapCounter) {
//   int pivotIndex = lo;

//   swap(arr[pivotIndex], arr[hi]);
//   int i = lo - 1;
//   for (int j = lo; j < hi; j++) {
//     if (arr[j] < arr[hi]) {
//       i++;
//       swap(arr[i], arr[j]);
//       swapCounter++;
//     }
//   }
//   swap(arr[i + 1], arr[hi]);
//   swapCounter++;
//   return i + 1;
// }

void quickSort(vector<int> &arr, int lo, int hi, unsigned long long int &swapCounter) {
  if (lo < hi) {
    int p = partition(arr, lo, hi, swapCounter);
    quickSort(arr, lo, p - 1, swapCounter);
    quickSort(arr, p + 1, hi, swapCounter);
  }
}

unsigned long long int qs() {
  PROCESS_MEMORY_COUNTERS beforeMem, afterMem;
  GetProcessMemoryInfo(GetCurrentProcess(), &beforeMem, sizeof(beforeMem));
  unsigned long long int swapCounter = 0;
  cout << "QuickSort, ";
  ofstream out;
  out.open("./sort/quickSort/out.txt");
  if (out.fail()) {
    cout << "Fail To Write on out.txt";
    exit(1);
  }

  vector<int> a;
  readFile(a);

  quickSort(a, 0, a.size() - 1, swapCounter);

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

// int main() {
//   qs();
// }
