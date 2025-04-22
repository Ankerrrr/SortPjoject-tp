#include "./resource/generateTestDat.hpp"
#include "sort/HeapSort/heapSort.cpp"
#include "sort/STL/STL_Sort.cpp"
#include "sort/boubleSort/boubleSort.cpp"
#include "sort/insertionSort/insertionSort.cpp"
#include "sort/mergeSort/mergeSort.cpp"
#include "sort/quickSort/quickSort.cpp"
#include "sort/selectionSort/selectionSort.cpp"

#include <chrono>

using namespace std;
using namespace std::chrono;

// change this adjust testData
#define testCase 7000
#define testRange 5000
#define loop 50

void recordTime(vector<double> &time, vector<unsigned long long int> &count, vector<unsigned long long int> &mem,
                unsigned long long int (*func)()) {
  auto start = high_resolution_clock::now();
  unsigned long long swapCounter = func();
  auto end = high_resolution_clock::now();

  double duration = duration_cast<microseconds>(end - start).count() / 1000.0;
  time.push_back(duration);
  count.push_back(swapCounter);
}

double worstTime(const vector<double> &v) {
  double longestTime = 0.0;
  for (double i : v) {
    if (i > longestTime)
      longestTime = i;
  }
  return longestTime;
}

double averageTime(const vector<double> &v) {
  double sum = 0;
  for (double i : v) {
    sum += i;
  }
  return sum / v.size();
}

unsigned int long long hiCount(const vector<unsigned long long int> &v) {
  unsigned int long long hi = 0;
  for (int i : v) {
    if (i > hi) {
      hi = i;
    }
  }
  return hi;
}

// int memAvg(vector<unsigned long long int> a) {
//   int sum = 0;
//   for (double i : a) {
//     sum += i;
//   }
//   return sum / a.size();
// }

int main() {
  vector<double> heapSortTime, boubleSortTime, inserSortTime,
      mergeSortTime, quickSortTime, selectionSortTime, STLSortTime, warnUp;
  vector<unsigned long long int> heapSortCount, boubleSortCount, inserSortCount,
      mergeSortCount, quickSortCount, selectionSortCount, warnUpC;
  vector<unsigned long long int> heapSortMem, boubleSortMem, inserSortMem,
      mergeSortMem, quickSortMem, selectionSortMem, STLSortMem, warnUpM;

  for (int i = 0; i < loop; i++) {
    generate(testCase, testRange);
    recordTime(warnUp, warnUpC, warnUpM, heap);
    recordTime(heapSortTime, heapSortCount, heapSortMem, heap);
    recordTime(boubleSortTime, boubleSortCount, boubleSortMem, bouble);
    recordTime(inserSortTime, inserSortCount, inserSortMem, inser);
    recordTime(mergeSortTime, mergeSortCount, mergeSortMem, mergeS);
    recordTime(quickSortTime, quickSortCount, quickSortMem, qs);
    recordTime(selectionSortTime, selectionSortCount, selectionSortMem, selectionSort);
    recordTime(STLSortTime, warnUpC, STLSortMem, STLsort);
    cout << endl;
  }

  cout << "---- Sorting Time Summary (ms) ----" << endl;
  cout << "Info : testCase = " << testCase << ", testRange = " << testRange << ", Loop = " << loop << endl;
  cout << "Heap Sort:      Avg =" << averageTime(heapSortTime) << ", Max = " << worstTime(heapSortTime) << ", SwapCountHighest = " << hiCount(heapSortCount) << endl;
  cout << "Bubble Sort:    Avg =" << averageTime(boubleSortTime) << ", Max = " << worstTime(boubleSortTime) << ", SwapCountHighest = " << hiCount(boubleSortCount) << endl;
  cout << "Insertion Sort: Avg =" << averageTime(inserSortTime) << ", Max = " << worstTime(inserSortTime) << ", SwapCountHighest = " << hiCount(inserSortCount) << endl;
  cout << "Merge Sort:     Avg =" << averageTime(mergeSortTime) << ", Max = " << worstTime(mergeSortTime) << ", SwapCountHighest = " << hiCount(mergeSortCount) << endl;
  cout << "Quick Sort:     Avg =" << averageTime(quickSortTime) << ", Max = " << worstTime(quickSortTime) << ", SwapCountHighest = " << hiCount(quickSortCount) << endl;
  cout << "Selection Sort: Avg =" << averageTime(selectionSortTime) << ", Max = " << worstTime(selectionSortTime) << ", SwapCountHighest = " << hiCount(selectionSortCount) << endl;
  cout << "STL Sort:       Avg =" << averageTime(STLSortTime) << ", Max = " << worstTime(STLSortTime) << endl;
}