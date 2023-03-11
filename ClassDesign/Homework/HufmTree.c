#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7
#define M (2 * N - 1)

typedef struct HufmTree {
    int weight,
        parent,
        lchild, rchild;
} HufmTree;

HufmTree tree[M + 1];

#define Maxval INT_MAX

void Huffman(HufmTree tree[]) {
    int i, j, p1, p2,
        small_1, small_2;

    memset(tree, 0, sizeof(HufmTree) * (M + 1));

    for (i = 1; i <= N; i++)
        scanf("%d", &tree[i].weight);

    for (i = N + 1; i <= M; i++) {
        p1 = p2 = 1;
        small_1 = small_2 = Maxval;
        for (j = 1; j < i - 1; j++)
            if (tree[j].parent == 0)
                if (tree[j].weight < small_1) {
                    small_2 = small_1;
                    p2 = p1;
                    small_1 = tree[j].weight;
                    p1 = j;
                } else if (tree[j].weight < small_2) {
                    small_2 = tree[j].weight;
                    p2 = j;
                }

        tree[i].weight = tree[p1].weight + tree[p2].weight;
        tree[i].lchild = p1;
        tree[i].rchild = p2;
        tree[p1].rchild = i;
        tree[p2].rchild = i;
    }
}