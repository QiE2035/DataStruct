#include "IndexTable.h"

int blockSearch(RecType R[], IndexTable Index[], int m, DataType k) {
    int i = 0, j;
    while ((i < m) && (k <= Index[i].index)) i++;
    if (i < m)
        for (j = Index[i].start; j <= Index[i].end; j++)
            if (k == R[j].key)
                return j;
    return 0;
}
