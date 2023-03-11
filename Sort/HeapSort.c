#include <stdio.h>
#include <stdlib.h>

#include "RecType.h"

void heapSift(RecType R[], int i, int n) {
    RecType rc = R[i];
    int j = 2 * i;
    while (j <= n) {
        if (j < n && R[j].key < R[j + 1].key)
            j++;
        if (rc.key > R[j].key)
            break;
        R[i] = R[j];
        i = j;
        j *= 2;
    }
    R[i] = rc;
}

void heapSort(RecType R[], int n) {
    int i;
    RecType x;
    for (i = n / 2; i >= 1; i--)
        heapSift(R, i, n);
    for (i = n; i > 1; i--) {
        x = R[i];
        R[i] = R[1];
        R[1] = x;
        heapSift(R, 1, i - 1);
    }
}

void printRec(RecType *R) {
    for (int i = 1; i <= N; i++)
        printf(" %d", R[i].key);
}

int main() {
    heapSort(gR, N);
    printRec(gR);

    putchar('\n');
    system("pause");
    return 0;
}
