#include <stdio.h>
#include <stdlib.h>

#include "RecType.h"

int partition(RecType *R, int low, int high) {
    int threshold; //临界值
    R[0] = R[low];
    threshold = R[low].key;
    while (low < high) {
        while ((low < high) && (R[high].key >= threshold)) high--;
        if (low < high)
            R[low] = R[high];
        while ((low < high) && (R[low].key <= threshold)) low++;
        if (low < high)
            R[high] = R[low];
    }
    R[low] = R[0];
    return low;
}

void quickSort(RecType *R, int low, int high) {
    int part;
    if (low < high) {
        part = partition(R, low, high);
        quickSort(R, low, part - 1);
        quickSort(R, part + 1, high);
    }
}

void printRec(RecType *R) {
    for (int i = 1; i <= N; i++) printf(" %d", R[i].key);
}

int main() {
    quickSort(gR, 1, N);
    printRec(gR);

    putchar('\n');
    system("pause");
    return 0;
}
