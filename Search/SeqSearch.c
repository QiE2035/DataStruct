#include "RecType.h"

int seqSearch(RecType R[], int n, DataType k) {
    int i = n;
    R[0].key = k;
    while (R[i].key != k) i--;
    return i;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%d\n", seqSearch(gR, N, 15));
    system("pause");
    return 0;
}
