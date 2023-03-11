#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "RecType.h"

void bubbleSort(RecType R[]) {
    for (int i = 1; i < N; i++) {
        bool flag = true;
        for (int j = 1; j <= N - 1; j++)
            if (R[j].key > R[j + 1].key) {
                RecType x = R[j];
                R[j] = R[j + 1];
                R[j + 1] = x;
                flag = false;
            }
        if (flag)
            break;
    }
}

void printRec(RecType *R) {
    for (int i = 1; i <= N; i++)
        printf(" %d", R[i].key);
}

int main() {
    bubbleSort(gR);
    printRec(gR);

    putchar('\n');
    system("pause");
    return 0;
}
