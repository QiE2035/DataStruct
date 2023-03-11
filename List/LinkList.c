#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *next;
} LinkList;

LinkList *creatHeadList()
{
    DataType data;
    LinkList *newNode, *L = NULL;

    scanf("%d", &data);

    while (data != -1)
    {
        newNode = (LinkList *)malloc(sizeof(LinkList));

        newNode->data = data;
        newNode->next = L;
        L = newNode;

        scanf("%d", &data);
    }

    return L;
}

void printJSON(LinkList *L)
{
    LinkList *nL = L;
    putchar('[');
    while (nL)
    {
        printf("%d, ", nL->data);
        nL = nL->next;
    }
    puts("\b\b]");
}

LinkList *creatTailList()
{
    int x;
    LinkList *s, *r = NULL, *L = NULL;

    scanf("%d", &x);
    while (x != -1)
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = x;
        if (!L)
            L = s;
        else
            r->next = s;
        r = s;
        scanf("%d", &x);
    }

    if (r)
        r->next = NULL;
    return L;
}

// have bug
LinkList *locateElem(LinkList *L, DataType x)
{
    LinkList *findNode = L->next;
    while (findNode && findNode->data != x)
    {
        findNode = findNode->next;
    }
    return findNode;
}

bool insert_y_x(LinkList *L, DataType y, DataType x)
{
    LinkList *p, *q, *s;
    p = L->next;
    q = L;

    while (p && p->data != y)
    {
        q = p;
        p = p->next;
    }

    if (!p)
    {
        fprintf(stderr, "error");
        return false;
    }

    s = (LinkList *)malloc(sizeof(LinkList));
    s->data = x;

    s->next = p;
    q->next = s;

    return true;
}

bool insert_y_x_next(LinkList *L, DataType y, DataType x)
{
    LinkList *findNode, *insertNode;
    findNode = L->next;

    while (findNode && findNode->data != y)
    {
        findNode = findNode->next;
    }

    if (!findNode)
    {
        fprintf(stderr, "error");
        return false;
    }

    insertNode = (LinkList *)malloc(sizeof(LinkList));
    insertNode->data = x;

    insertNode->next = findNode->next;
    findNode->next = insertNode;

    return true;
}

void deleteElemNode(LinkList *L, LinkList *delNode)
{
    LinkList *preNode = L;

    while (preNode->next != delNode)
        preNode = preNode->next;

    preNode->next = delNode->next;

    free(delNode);
}

bool deleteElem(LinkList *L, int i)
{
    LinkList *p = L, *q;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p && p->next)
    {
        q = p->next;
        p->next = q->next;
        free(q);
        return true;
    }
}

bool deleteValue(LinkList *L, DataType x)
{
    LinkList *findNode = L->next, *preNode = L;

    while (findNode && findNode->data != x)
    {
        preNode = findNode;
        findNode = findNode->next;
    }

    if (!findNode || !findNode->next)
    {
        fprintf(stderr, "error");
        return false;
    }

    preNode->next = findNode->next;
    free(findNode);
    return true;
}

LinkList *findMidNode(LinkList *L)
{
    LinkList *slow = L, *fast = L;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void deleteDupNode(LinkList *L)
{
    LinkList *findNode = L, *curNode = L->next, *tmpNode;
    while (findNode->next)
    {
        findNode = findNode->next;
        while (curNode->next)
        {
            if (curNode->next->data != findNode->data)
                curNode = curNode->next;
            else
            {
                tmpNode = curNode->next;
                curNode->next = tmpNode->next;
                free(tmpNode);
            }
        }
    }
}

int countX(LinkList *L, DataType x)
{
    int count = 0;
    while (L)
    {
        if (L->data == x)
            count++;
        L = L->next;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    LinkList *L = creatTailList();

    printf("%d\n", countX(L, 0));
}
