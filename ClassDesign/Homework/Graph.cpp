/**
 * @file Graph.cpp
 * @author 杜思维 (计算机212-15)
 * @brief 无序图的邻接矩阵 (静态)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/**
 * @brief 顶点数
 *
 */
#define N 4
/**
 * @brief 边数
 *
 */
#define E 5

/**
 * @brief 顶点类型
 *
 */
typedef char VexType;
/**
 * @brief 边类型
 *
 */
typedef int AdjType;

/**
 * @brief 邻接矩阵
 *
 */
typedef struct AdjMatrix {
    /**
     * @brief 顶点数组
     *
     */
    VexType vertex[N + 1];
    /**
     * @brief 边数组
     *
     */
    AdjType edge[N + 1][N + 1];
} AdjMatrix;

/**
 * @brief 创建邻接矩阵
 *
 * @param adj 邻接矩阵指针
 */
void createAdj(AdjMatrix *adj) {
    int i, j;
    fflush(stdin);
    printf("请输入顶点的信息 (共 %d 个): ", N);
    fflush(stdin);
    for (int i = 1; i <= N; i++)
        while ((adj->vertex[i] = getchar()) == '\n' ||
               adj->vertex[i] == ',' ||
               adj->vertex[i] == ' ') {
            cout << "输入未完成，请继续: ";
        }
    fflush(stdin);

    printf("请输入各边的信息 (格式如 1,2 ) (共 %d 个): ", N);
    memset(adj->edge, 0, sizeof(adj->edge));
    fflush(stdin);
    for (int k = 1; k <= E; k++) {
        scanf("%d,%d", &i, &j);
        adj->edge[i][j] = adj->edge[j][i] = 1;
    }
}

/**
 * @brief 输出邻接矩阵
 *
 * @param adj 邻接矩阵指针
 */
void printAdj(AdjMatrix *adj) {
    printf("顶点:");
    for (int i = 1; i <= N; i++)
        printf(" %c", adj->vertex[i]);
    putchar('\n');

    puts("矩阵:");
    for (int i = 1; i <= N; i++) {
        cout << ' ';
        for (int j = 1; j <= N; j++)
            printf(" %d", adj->edge[i][j]);
        cout << endl;
    }
}

/**
 * @brief DFS 遍历标志
 *
 */
uint8_t visitedDFS[N + 1] = {};

/**
 * @brief DFS 递归函数 (仅递归用, 常规请使用 DFS 函数)
 *
 * @param i 行下标
 * @param adj 邻接矩阵指针
 */
void _DFS(int i, AdjMatrix *adj) {
    printf("  访问第 %d 个节点: %c \n", i, adj->vertex[i]);
    visitedDFS[i] = 1;
    for (int j = 1; j <= N; j++)
        if ((adj->edge[i][j]) && (!visitedDFS[j]))
            _DFS(j, adj);
}

/**
 * @brief DFS 内联函数
 *
 * @param start 开始节点
 * @param adj 邻接矩阵指针
 */
inline void DFS(int start, AdjMatrix *adj) {
    cout << "DFS: " << endl;
    memset(visitedDFS, 0, sizeof(visitedDFS));
    _DFS(1, adj);
}

/**
 * @brief BFS 函数
 *
 * @param start 开始节点
 * @param adj 邻接矩阵指针
 */
void BFS(int start, AdjMatrix *adj) {
    int visited[N + 1] = {};
    queue<int> sq;

    cout << "BFS: " << endl;
    cout << "  访问第 " << start << " 个节点: " << adj->vertex[start] << endl;
    visited[start] = 1;
    sq.push(start);
    while (!sq.empty()) {
        int i = sq.front();
        sq.pop();
        for (int j = 1; j <= N; j++)
            if ((adj->edge[i][j]) && (!visited[j])) {
                cout << "  访问第 " << j << " 个节点: " << adj->vertex[j] << endl;
                visited[j] = 1;
                sq.push(j);
            }
    }
}

/**
 * @brief 主函数
 *
 * @return int 运行结果
 */
int main() {
    AdjMatrix adj, *pAdj = &adj;

    while (true) {
        system("cls");

        createAdj(pAdj);
        printAdj(pAdj);
        DFS(1, pAdj);
        BFS(1, pAdj);

        system("pause");
    }
}
