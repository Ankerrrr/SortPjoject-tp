# sort 資料結構作業報告

## 成員

41243243(黃安可)

41243244(黃順駿)

---

## 簡單說明

測試各個 SORT 的執行時間，包含以下

> bouble, heap, insertion, merge, quick, selection, STL Sort

## 使用方式

執行 RunSort cpp 檔案

## 說明

主程式：RunCode

    包含七種排序法的 .cpp 檔案（例如：BubbleSort.cpp、QuickSort.cpp 等）。

    負責整體流程的執行與排序方法的呼叫。

    執行後會在主程式目錄下產生輸出檔案 out.txt。

    並產生執行報告

產生亂數：resource/generateTestDat.cpp

    用以產生亂數數值到 dat.txt 檔案內

資料來源：resource/dat.txt

    存放待排序的亂數資料。

    由 generateTestDat 自動產生亂數並寫入 dat.txt。

資料讀取：ReadFile.cpp

    負責讀取 dat.txt 中的資料。

    將亂數資料讀入記憶體，提供給各種排序方法使用。

排序: Sort/ { 各種 SORT } / sort.cpp

    七種排序方法寫在Sort資料夾內，在RunCode主程式呼叫他們

# 程式架構

## 使用到的函式庫

### STL

```cpp
#include <chrono> //用於分析執行時間
#include <ctime> //用於計算執行時間
#include <fstream> //用於輸入輸出TXT檔案
#include <iostream> //一定要的
#include <vector> //用來儲存陣列
```

### 自己的.hpp 檔案

```cpp
#include "./resource/generateTestDat.hpp" //產生亂數
#include "sort/HeapSort/heapSort.cpp" //heapSort排序
#include "sort/STL/STL_Sort.cpp"//STL排序
#include "sort/boubleSort/boubleSort.cpp"//boubleSort排序
#include "sort/insertionSort/insertionSort.cpp"//insertionSort排序
#include "sort/mergeSort/mergeSort.cpp"//mergeSort排序
#include "sort/quickSort/quickSort.cpp"//quickSort排序
#include "sort/selectionSort/selectionSort.cpp"//selectionSort排序
```

## 可調整參數

```
testCase 1000
testRange 10000
define loop 50
```

- testCase 用於修改 dat 要產生多少數組
- testRange 用於修改 dat 要產生的數值從 1 到多少
- loop 調整要測試幾次

> [!NOTE]
>
> 此定義於 Runsort 內調整

## 輸出

這是一個 `testCase: 1000` , `testRange: 10000` , `loop: 50` 的範例

如下表即顯示各個 SORT 在 LOOP 次的 avg 及 Max (單位: ms)

以及在程式內 Swap 交換的次數 (SwapCountHiggest)最高

最下方則是使用 STL SORT 的排序

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 1000, testRange = 10000, Loop = 50
Heap Sort:      Avg =1.27098, Max = 3.243, SwapCountHiggest = 9090
Bubble Sort:    Avg =6.85076, Max = 14.831, SwapCountHiggest = 248536
Insertion Sort: Avg =2.69018, Max = 4.87, SwapCountHiggest = 248536
Merge Sort:     Avg =2.01478, Max = 3.059, SwapCountHiggest = 9976
Quick Sort:     Avg =1.23622, Max = 2.283, SwapCountHiggest = 6438
Selection Sort: Avg =4.49724, Max = 6.979, SwapCountHiggest = 238206
STL Sort:       Avg =1.24468, Max = 2.545
```

## 分析

### 測試環境

測試平台：

- CPU: Intel Core i7-12650H
- RAM: 16 GB
- Compiler: g++ 13.2.0
- OS: Windows 11

---

測試數據

`testCase: 10` , `testRange: 5000` , `loop: 50`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 10, testRange = 5000, Loop = 50
  Heap Sort:      Avg =0.5563, Max = 6.042, SwapCountHiggest = 25
Bubble Sort:    Avg =0.3986, Max = 0.758, SwapCountHiggest = 23
Insertion Sort: Avg =0.43394, Max = 0.954, SwapCountHiggest = 23
Merge Sort:     Avg =0.42774, Max = 0.768, SwapCountHiggest = 34
Quick Sort:     Avg =0.39844, Max = 0.538, SwapCountHiggest = 18
Selection Sort: Avg =0.41796, Max = 0.657, SwapCountHiggest = 23
STL Sort:       Avg =0.41266, Max = 0.718
```

`testCase: 1000` , `testRange: 5000` , `loop: 50`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 1000, testRange = 5000, Loop = 50
Heap Sort:      Avg =1.24846, Max = 2.247, SwapCountHiggest = 9134
Bubble Sort:    Avg =6.74482, Max = 9.45, SwapCountHiggest = 261327
Insertion Sort: Avg =2.8325, Max = 7.007, SwapCountHiggest = 261327
Merge Sort:     Avg =1.97966, Max = 3.011, SwapCountHiggest = 9976
Quick Sort:     Avg =1.18906, Max = 1.594, SwapCountHiggest = 6489
Selection Sort: Avg =4.45702, Max = 6.533, SwapCountHiggest = 253188
STL Sort:       Avg =1.21592, Max = 1.97
```

`testCase: 5000` , `testRange: 5000` , `loop: 50`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 5000, testRange = 5000, Loop = 50
Heap Sort:      Avg =7.43948, Max = 14.41, SwapCountHighest = 57236
Bubble Sort:    Avg =150.42, Max = 155.508, SwapCountHighest = 6386102
Insertion Sort: Avg =43.5099, Max = 57.363, SwapCountHighest = 6386102
Merge Sort:     Avg =11.1709, Max = 22.758, SwapCountHighest = 61808
Quick Sort:     Avg =6.99538, Max = 11.87, SwapCountHighest = 45959
Selection Sort: Avg =100.465, Max = 116.685, SwapCountHighest = 5518686
STL Sort:       Avg =6.80112, Max = 11.164
```

`testCase: 10000` , `testRange: 5000` , `loop: 50`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 10000, testRange = 5000, Loop = 50
Heap Sort:      Avg =8.93592, Max = 16.62, SwapCountHiggest = 124308
Bubble Sort:    Avg =597.013, Max = 613.529, SwapCountHiggest = 25379343
Insertion Sort: Avg =153.084, Max = 174.375, SwapCountHiggest = 25379343
Merge Sort:     Avg =18.2174, Max = 40.059, SwapCountHiggest = 133616
Quick Sort:     Avg =8.38628, Max = 15.585, SwapCountHiggest = 99076
Selection Sort: Avg =368.23, Max = 386.652, SwapCountHiggest = 18974693
STL Sort:       Avg =8.2887, Max = 14.96
```

### 這邊開始跑太久了所以降低 LOOP 次數

`testCase: 50000` , `testRange: 5000` , `loop: 1`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 50000, testRange = 5000, Loop = 1
Heap Sort:      Avg =85.296, Max = 85.296, SwapCountHiggest = 737622
Bubble Sort:    Avg =14994.1, Max = 14994.1, SwapCountHiggest = 625516856
Insertion Sort: Avg =3708.43, Max = 3708.43, SwapCountHiggest = 625516856
Merge Sort:     Avg =193.477, Max = 193.477, SwapCountHiggest = 784464
Quick Sort:     Avg =72.361, Max = 72.361, SwapCountHiggest = 420997
Selection Sort: Avg =6087.38, Max = 6087.38, SwapCountHiggest = 209299692
STL Sort:       Avg =71.148, Max = 71.148
```

`testCase: 100000` , `testRange: 5000` , `loop: 1`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 100000, testRange = 5000, Loop = 1
Heap Sort:      Avg =175.199, Max = 175.199, SwapCountHiggest = 1574760
Bubble Sort:    Avg =58675.4, Max = 58675.4, SwapCountHiggest = 18446744071918634865
Insertion Sort: Avg =15218.5, Max = 15218.5, SwapCountHiggest = 18446744071918634865
Merge Sort:     Avg =393.943, Max = 393.943, SwapCountHiggest = 1668928
Quick Sort:     Avg =150.664, Max = 150.664, SwapCountHiggest = 1028860
Selection Sort: Avg =18950.3, Max = 18950.3, SwapCountHiggest = 473874715
STL Sort:       Avg =149.034, Max = 149.034
```

## memory Record

```
heapSort, ----------------------
Memory Info (Before):
  Working Set Size:       5020 KB
  Peak Working Set Size:  5020 KB
  Pagefile Usage:         1308 KB
Memory Info (After):
  Working Set Size:       5020 KB
  Peak Working Set Size:  5020 KB
  Pagefile Usage:         1308 KB
----------------------
boubleSort, ----------------------
Memory Info (Before):
  Working Set Size:       5024 KB
  Peak Working Set Size:  5024 KB
  Pagefile Usage:         1308 KB
Memory Info (After):
  Working Set Size:       5024 KB
  Peak Working Set Size:  5024 KB
  Pagefile Usage:         1308 KB
----------------------
insertionSort, ----------------------
Memory Info (Before):
  Working Set Size:       5024 KB
  Peak Working Set Size:  5024 KB
  Pagefile Usage:         1308 KB
Memory Info (After):
  Working Set Size:       5024 KB
  Peak Working Set Size:  5024 KB
  Pagefile Usage:         1308 KB
----------------------
mergeSort, ----------------------
Memory Info (Before):
  Working Set Size:       5028 KB
  Peak Working Set Size:  5028 KB
  Pagefile Usage:         1308 KB
Memory Info (After):
  Working Set Size:       5028 KB
  Peak Working Set Size:  5028 KB
  Pagefile Usage:         1308 KB
----------------------
QuickSort, ----------------------
Memory Info (Before):
  Working Set Size:       5028 KB
  Peak Working Set Size:  5028 KB
  Pagefile Usage:         1308 KB
Memory Info (After):
  Working Set Size:       5028 KB
  Peak Working Set Size:  5028 KB
  Pagefile Usage:         1308 KB
----------------------
SelectionSort, ----------------------
Memory Info (Before):
  Working Set Size:       5028 KB
  Peak Working Set Size:  5028 KB
  Pagefile Usage:         1308 KB
Memory Info (After):
  Working Set Size:       5028 KB
  Peak Working Set Size:  5028 KB
  Pagefile Usage:         1308 KB
----------------------
SelectionSort, ----------------------
Memory Info (Before):
  Working Set Size:       5028 KB
  Peak Working Set Size:  5028 KB
  Pagefile Usage:         1308 KB
Memory Info (After):
  Working Set Size:       5028 KB
  Peak Working Set Size:  5028 KB
  Pagefile Usage:         1308 KB
----------------------
```

```cpp
   char *p = new char[10 * 1024 * 1024]; // 分配 10MB
   for (int i = 0; i < 10 * 1024 * 1024; i += 4096) {
        p[i] = 0; // 實際觸發分頁配置
   }
```

> [!CAUTION]
>
> 似乎是用量過少，對於記憶體顯示不明顯，加入上方程式數值即會增加，可見為因為用量過少導致增長不明顯。

## 其他

### warnUp

發現如果直接執行 SORT 第一個跑的 SORT 會表現很差，所以我在第一個執行了一個沒有意義的排序函示，類似讓電腦先做的熱身運動，才不會影響測試數據。

### windowsAPI 在 vscode 的問題

```cpp
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define PSAPI_VERSION 1
#include <windows.h>
#include <psapi.h>
```

發現要跑上面那三個 define 才能正常編譯。

### vscode task.json

```json
{
  "tasks": [
    {
      "type": "cppbuild",
      "label": "C/C++: g++.exe build active file",
      "command": "C:\\mingw64\\bin\\g++.exe",
      "args": [
        "-fdiagnostics-color=always",
        "-g",
        "RunSort(RunThisCode).cpp",
        "resource/generateTestDat.cpp",
        "sort/ReadFile.cpp",
        "-o",
        "${fileDirname}\\RunSort(RunThisCode).exe",
        "-lpsapi"
      ],
      "options": {
        "cwd": "${fileDirname}"
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "detail": "Task generated by Debugger."
    }
  ],
  "version": "2.0.0"
}
```

## 折線圖

> 資料比數 - 花費時間折線圖
> ![圖表](./Img/a.png)

> 資料比數 - 花費時間折線圖(放大之後)
> ![圖表](./Img/b.png)

> [!NOTE]
>
> 結果符合 QuickSort 、 HeapSort 、 Merge Sort 時間複雜度為 O(n log n)

| 排序方法       | 平均時間複雜度 |
| -------------- | -------------- |
| Quick Sort     | O(n log n)     |
| Heap Sort      | O(n log n)     |
| Merge Sort     | O(n log n)     |
| Insertion Sort | O(n²)          |
| Selection Sort | O(n²)          |
| Bubble Sort    | O(n²)          |

## 速度排序

測資夠大的話

quick 略優 Heap 優於 Merge 大優於 Inesrtion 優於 selection 大大優於 Bubble

## 驗證 QuickSort MergeSort 資料整齊是否影響排序時間

使用 7000 筆資料測試 測試 50 次相同測資

| 排序方法                 | 整齊(max) | 亂數(max) |
| ------------------------ | --------- | --------- |
| Quick Sort(pivot 選中間) | 17.37     | 15.973    |
| Quick Sort(pivot 選左邊) | 87.168    | 13.724    |
| Merge Sort               | 47.75     | 57.738    |

QuickSort 可以發現非常戲劇性的結果，如果是整齊的資料對於選最左邊當 PIVOT 會有很大的影響，但對於選中間當 PIVOT 影響就不大，

MergeSort 則呈現穩定狀態，兩者幾乎沒有差距。

## 心得

雖然過程一度想要放棄，建造有點規模的程式是真的有點痛苦，但最後看到成果還是非常的開心的!

總結:
這個作業很好玩，我們都學到了很多!!
