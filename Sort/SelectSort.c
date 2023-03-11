#include <stdio.h>
#include <stdlib.h>

#include "RecType.h"

void slectSort(RecType R[]) {
    for (int i = 1; i < N; i++) {
        int k = i;
        for (int j = i + 1; j <= N; j++) {
            if (R[j].key < R[k].key) {
                k = j;
            }
            if (k != i) {
                RecType x = R[i];
                R[i] = R[k];
                R[k] = x;
            }
        }
    }
}

void printRec(RecType *R) {
    for (int i = 1; i <= N; i++) printf(" %d", R[i].key);
}

int main() {
    slectSort(gR);
    printRec(gR);

    putchar('\n');
    system("pause");
    return 0;
}
