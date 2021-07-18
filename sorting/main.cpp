#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insertionSort(vector<T> &list) {
    // 前i個為已排序好的元素，將第i+1個往前插入合適的位置
    // 然後重複此步驟直到結束。
    for (int i = 1; i < list.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (list[j] < list[j - 1]) {
                swap(list[j - 1], list[j]);
            } else {
                break;
            }
        }
    }
}

template <typename T>
void selectionSort(vector<T> &list) {
    // 前i個為已排序好的元素，找到剩餘元素中的最小值，
    // 與第i+1個交換，重複此步驟直到最後。
    for (int i = 0; i < list.size(); i++) {
        int min = i;
        for (int j = i + 1; j < list.size(); j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        // swap
        swap(list[i], list[min]);
    }
}

template <typename T>
void bubbleSort(vector<T> &list) {
    // 每輪都掃一遍陣列，當有元素錯序時，將其交換，持續進行N輪(N為元素個素)，
    // 如每輪結束未發生錯位即表示已排序完成，可提早停止。
    for (int i = 0; i < list.size(); i++) {
        int hasChange = false;
        for (int j = 0; j < list.size() - 1; j++) {
            if (list[j] > list[j + 1]) {
                //cout << "(" << i << ") swap " << list[j] << " <-> " << list[j + 1] << endl;
                swap(list[j], list[j + 1]);
                hasChange = true;
            }
        }
        if (!hasChange) {
            break;
        }
    }
}

template <typename T>
void quickSort(vector<T> &list, int start, int end) {
    if (start >= end) {
        return ;
    }
    int pivotIdx = start;
    // 讓[start]為pivot，並且將其搬至序列最後一位。
    T pivot = list[pivotIdx];
    swap(list[pivotIdx], list[end]);
    for (int i = start; i < end; i++) {
        if (list[i] <= pivot) {
            swap(list[pivotIdx], list[i]);
            pivotIdx++;
        }
    }
    // 將pivot從最末位搬回至pivotIdx，此時pivot已位於正確的位置
    swap(list[pivotIdx], list[end]);
    // 排序pivot左邊的序列
    quickSort(list, start, pivotIdx - 1);
    // 排序pivot右邊的序列
    quickSort(list, pivotIdx + 1, end);
}

template <typename T>
void mergeSort(vector<T> &list, int start, int end) {
    if (start >= end) {
        return ;
    }
    int mid = start + (end - start) / 2;
    // 合併排序左半邊
    mergeSort(list, start, mid);
    // 合併排序右半邊
    mergeSort(list, mid + 1, end);
    // 使用insertion sort技巧合併兩個序列
    for (int i = mid + 1; i < end; i++) {
        for (int j = i; j > 0; j--) {
            if (list[j - 1] > list[j]) {
                swap(list[j - 1], list[j]);
            } else {
                break;
            }
        }
    }
}

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
string vectorToString(const vector<T> &list) {
    string ret = "";
    for (auto it = list.begin(); it != list.end(); it++) {
        if (ret.length() > 0) {
            ret = ret + ", " + to_string(*it);
        } else {
            ret = ret + to_string(*it);
        }
    }
    return ret;
}

int main() {
    vector<int> list = { 5, 9, 6, 0 , 2, -3, 7, -8, 20 };
    cout << "[InsertionSort] BEFORE: " << vectorToString(list) << endl;
    insertionSort(list);
    cout << "[InsertionSort] AFTER: " << vectorToString(list) << endl;

    list = { 5, 9, 6, 0 , 2, -3, 7, -8, 20 };
    cout << "[SelectionSort] BEFORE: " << vectorToString(list) << endl;
    selectionSort(list);
    cout << "[SelectionSort] AFTER: " << vectorToString(list) << endl;

    list = { 5, 9, 6, 0 , 2, -3, 7, -8, 20 };
    cout << "[BubbleSort] BEFORE: " << vectorToString(list) << endl;
    bubbleSort(list);
    cout << "[BubbleSort] AFTER: " << vectorToString(list) << endl;

    list = { 5, 9, 6, 0 , 2, -3, 7, -8, 20 };
    cout << "[QuickSort] BEFORE: " << vectorToString(list) << endl;
    quickSort(list, 0, list.size() - 1);
    cout << "[QuickSort] AFTER: " << vectorToString(list) << endl;

    list = { 5, 9, 6, 0 , 2, -3, 7, -8, 20 };
    cout << "[MergeSort] BEFORE: " << vectorToString(list) << endl;
    mergeSort(list, 0, list.size() - 1);
    cout << "[MergeSort] AFTER: " << vectorToString(list) << endl;
    return 0;
}
