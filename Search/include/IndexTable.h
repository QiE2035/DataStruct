#ifndef _INDEX_TABLE_
#define _INDEX_TABLE_

#include "RecType.h"

#define MAX_SIZE 10

typedef DataType IndexType;

typedef struct IndexTable {
    IndexType index;
    int start, end;
} IndexTable;

IndexTable gI[MAX_SIZE];

#endif // _INDEX_TABLE_
