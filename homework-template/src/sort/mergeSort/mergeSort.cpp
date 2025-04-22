#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
using namespace std;

void merge(vector<int> &arr, int lo, int mid, int hi, unsigned long long int &swapCounter) {
  vector<int> left(arr.begin() + lo, arr.begin() + mid + 1);
  vector<int> right(arr.begin() + mid + 1, arr.begin() + hi + 1);
  int i = 0, j = 0, k = lo;
  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
    swapCounter++;
  }
  while (i < left.size()) {
    arr[k++] = left[i++];
    swapCounter++;
  }
  while (j < right.size()) {
    arr[k++] = right[j++];
    swapCounter++;
  }
}

void mergeSort(vector<int> &arr, int lo, int hi, unsigned long long int &swapCounter) {
  if (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    mergeSort(arr, lo, mid, swapCounter);
    mergeSort(arr, mid + 1, hi, swapCounter);
    merge(arr, lo, mid, hi, swapCounter);
  }
}

unsigned long long int mergeS() {
  PROCESS_MEMORY_COUNTERS beforeMem, afterMem;
  GetProcessMemoryInfo(GetCurrentProcess(), &beforeMem, sizeof(beforeMem));
  unsigned long long int swapCounter = 0;
  cout << "mergeSort, ";
  ofstream out;
  out.open("./sort/mergeSort/out.txt");
  if (out.fail()) {
    cout << "Fail To Write on out.txt";
    exit(1);
  }

  vector<int> a;
  readFile(a);

  mergeSort(a, 0, a.size() - 1, swapCounter);

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
//   mergeS();
// }
