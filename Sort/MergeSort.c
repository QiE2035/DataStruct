#include <stdio.h>
#include <stdlib.h>

#include "RecType.h"

void merge(RecType R[], RecType A[], int u, int v, int t) {
    int i = u, j = v + 1, k = u;

    while (i <= v && j <= t)
        if (R[i].key <= R[j].key)
            A[k++] = R[i++];
        else
            A[k++] = R[j++];

    while (i <= v) A[k++] = R[i++];

    while (j <= t) A[k++] = R[j++];
}

void mergePass(RecType R[], RecType A[], int n, int len) {
    int p, i;

    for (p = 1; p + 2 * len - 1 <= n; p = p + 2 * len)
        merge(R, A, p, p + len - 1, p + 2 * len - 1);

    if (p + len - 1 < n)
        merge(R, A, p, p + len - 1, n);
    else
        for (i = p; i <= n; i++) A[i] = R[i];
}

void mergeSort(RecType R[], int n) {
    RecType A[N + 1];
    int i, len = 1;
    while (len < n) {
        mergePass(R, A, n, len);
        len *= 2;
        mergePass(A, R, n, len);
        len *= 2;
    }
}

void printRec(RecType *R) {
    for (int i = 1; i <= N; i++) printf(" %d", R[i].key);
}

int main() {
    mergeSort(gR, N);
    printRec(gR);

    putchar('\n');
    system("pause");
    return 0;
}
