/**
 * @file Sort.cpp
 * @author 杜思维 (计算机212-15)
 * @brief 快速排序 堆排序
 * @version 0.1
 * @date 2022-12-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 数据类型
 *
 */
typedef int DataType;

/**
 * @brief 快速排序分割
 *
 * @param R 待排序内容
 * @param low 低下标
 * @param high 高下标
 * @return int 分割下标
 */
int partition(vector<DataType> &R, int low, int high) {
    int threshold = R[0] = R[low]; // 临界值
    while (low < high) {
        while ((low < high) && (R[high] >= threshold)) high--;
        if (low < high)
            R[low] = R[high];
        while ((low < high) && (R[low] <= threshold)) low++;
        if (low < high)
            R[high] = R[low];
    }
    R[low] = R[0];
    return low;
}

/**
 * @brief 快速排序递归
 *
 * @param R 待排序内容
 * @param low 低下标
 * @param high 高下标
 */
void quickSort(vector<DataType> &R, int low, int high) {
    if (low < high) {
        int part = partition(R, low, high);
        quickSort(R, low, part - 1);
        quickSort(R, part + 1, high);
    }
}

/**
 * @brief 快速排序 (内联)
 *
 * @param R 待排序内容
 */
inline void quickSort(vector<DataType> &R) {
    quickSort(R, 1, R.size() - 1);
    R[0] = 0;
}

/**
 * @brief 堆排序调整
 *
 * @param R 待排序内容
 * @param start 起始下标
 * @param end 结束下标
 */
void heapSift(vector<DataType> &R, int start, int end) {
    DataType rc = R[start];
    int big = 2 * start;
    while (big <= end) {
        if (big < end && R[big] < R[big + 1])
            big++;
        if (rc > R[big])
            break;
        R[start] = R[big];
        start = big;
        big *= 2;
    }
    R[start] = rc;
}

/**
 * @brief 堆排序
 *
 * @param R 待排序内容
 * @param n 元素数量
 */

void heapSort(vector<DataType> &R, int n) {
    for (int i = n / 2; i >= 1; i--)
        heapSift(R, i, n);
    for (int i = n; i > 1; i--) {
        DataType x = R[i];
        R[i] = R[1];
        R[1] = x;
        heapSift(R, 1, i - 1);
    }
}

/**
 * @brief 堆排序 (内联)
 *
 * @param R 待排序内容
 */
inline void heapSort(vector<DataType> &R) {
    heapSort(R, R.size() - 1);
    R[0] = 0;
}

/**
 * @brief  输出向量
 *
 * @tparam T   元素类型
 * @param  tip 输出提示
 * @param  R   目标向量
 */
template <typename T>
void printVector(string tip, vector<T> &R) {
    cout << tip << ": ";
    for (auto &&data : R)
        if (data)
            cout << data << ' ';
    cout << endl;
}

int main(int argc, char const *argv[]) {
    while (true) {
        vector<DataType> R(1, 0), R2;
        DataType data;

        system("cls");

        cout << "请输入数据, 类型为 "
             << typeid(DataType).name()
             << ", 以空格分隔, 以 0 结束: ";
        do {
            cin >> data;
            R.push_back(data);
        } while (data);
        R2 = R;

        quickSort(R);
        printVector("快速排序", R);

        heapSort(R2);
        printVector("堆排序", R2);

        system("pause");
    }
}
