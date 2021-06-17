
#include <stdio.h>
#include <stdlib.h>
typedef struct listNode
{
    int dest;
    struct listNode *next;
} listNode;
typedef struct list
{
    listNode *head;
} list;
typedef struct graph
{
    int v;
    list *array;
} graph;
listNode *createNode(int dest)
{
    listNode *newNode = (listNode *)malloc(sizeof(listNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
graph *createGraph(int v)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->v = v;
    g->array = (list *)malloc(v * sizeof(list));
    for (int i = 0; i < v; i++)
    {
        g->array[i].head = NULL;
    }
    return g;
}
void addEdge(graph *g, int s, int d)
{
    listNode *newNode = createNode(d);
    newNode->next = g->array[s].head;
    g->array[s].head = newNode;
    newNode = createNode(s);
    newNode->next = g->array[d].head;
    g->array[d].head = newNode;
}
void display(graph *g)
{
    for (int i = 0; i < g->v; i++)
    {
        listNode *temp = g->array[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (temp)
        {
            printf("-> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int v = 5;
    graph *g = createGraph(v);
    int src, dest;
    int ch;
    int mat[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            mat[i][j] = 0;
        }
    }
    while (1)
    {
        printf("Enter src:");
        scanf("%d", &src);
        printf("Enter dest:");
        scanf("%d", &dest);
        addEdge(g, src, dest);
        mat[src][dest] = 1;
        mat[dest][src] = 1;
        printf("Continue?");
        scanf("%d", &ch);
        if (!ch)
            break;
    }
    display(g);
    printf("\nAdjacency matrix:\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}