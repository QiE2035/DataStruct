#include "RecType.h"

/**
 * @brief 二分法查找
 *
 * @param R 数据记录
 * @param count 数据数量
 * @param key 关键字
 * @return int 下标, 从 1 开始, 为 0 时表示未找到
 */
int binarySearch(RecType R[], int count, DataType key) {
    int low = 1, high = count, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (key == R[mid].key)
            return mid;
        else if (key < R[mid].key)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%d\n", binarySearch(gR, N, 15));
    system("pause");
    return 0;
}
