#include <stdio.h>
#include <stdlib.h>

#include "RecType.h"

void shellInsert(RecType R[], int d) {
    int i, j;
    for (i = d + 1; i <= N; i++) {
        R[0] = R[i];
        while (j > 0 && R[j].key > R[0].key) {
            R[j + d] = R[j];
            j -= d;
        }
    }
}

void shellSort(RecType R[], int d[], int t) {
    for (int k = 0; k < t; k++) { shellInsert(R, d[k]); }
}

void printRec(RecType *R) {
    for (int i = 1; i <= N; i++) printf(" %d", R[i].key);
}

int main() {
    int d[] = {5, 3, 1};
    shellSort(gR, d, 3);
    printRec(gR);

    putchar('\n');
    system("pause");
    return 0;
}
