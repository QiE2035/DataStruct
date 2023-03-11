#include <stdio.h>
#include <stdlib.h>

#include "RecType.h"

void insertSort() {
    int i, j;
    for (i = 2; i <= N; i++) {
        gR[0] = gR[i];
        j = i - 1;
        while (gR[0].key < gR[j].key) {
            gR[j + 1] = gR[j];
            j--;
        }
        gR[j + 1] = gR[0];
    }
}

void printRec() {
    for (int i = 1; i <= N; i++) { printf(" %d", gR[i].key); }
}

int main() {
    insertSort();
    printRec();

    putchar('\n');
    system("pause");
    return 0;
}
