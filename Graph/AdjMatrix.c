#include <stdio.h>
#include <stdlib.h>

#define N 5 //顶点数
#define E 6 //边数
// #define MAX INT_MAX

typedef char VexType;
typedef int AdjType;

typedef struct AdjMatrix {
    VexType vertex[N + 1];
    AdjType edge[N + 1][N + 1];
} AdjMatrix;

void createAdj(AdjMatrix *adj) {
    int i, j, k;
    printf("请输入顶点的信息: ");
    for (i = 1; i <= N; i++)
        adj->vertex[i] = getchar();
    printf("请输入各边的信息: ");
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            adj->edge[i][j] = 0;
    for (k = 1; k < E; k++) {
        scanf("%d,%d", &i, &j);
        adj->edge[i][j] = adj->edge[j][i] = 1;
    }
}

void printAdj(AdjMatrix *adj) {
    printf("顶点:");
    for (int i = 1; i <= N; i++)
        printf(" %c", adj->vertex[i]);
    putchar('\n');

    puts("矩阵:");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            printf(" %d", adj->edge[i][j]);
        putchar('\n');
    }
}

void _DFS(int i, AdjMatrix *adj) {
    static int visited[N + 1];
    int j;
    printf("访问第 %d 个点: %c \n", i, adj->vertex[i]);
    visited[i] = 1;
    for (j = 1; j <= N; j++)
        if ((adj->edge[i][j]) && (!visited[j]))
            _DFS(j, adj);
}

int main() {
    AdjMatrix adj;

    createAdj(&adj);
    printAdj(&adj);
    _DFS(1, &adj);

    system("pause");
    return 0;
}
