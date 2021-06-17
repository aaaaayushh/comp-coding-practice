#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

int max(int a, int b)
{
    return (a >= b) ? a : b;
}
int height(Node *root, int *ans)
{
    if (!root)
        return 0;
    int lHeight = height(root->left, ans);
    int rHeight = height(root->right, ans);

    *ans = max(*ans, 1 + lHeight + rHeight);
    return 1 + max(lHeight, rHeight);
}

int diameter(Node *root)
{
    if (!root)
        return 0;
    int ans = INT_MIN;
    height(root, &ans);
    return ans;
}

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node *create_bt(Node *root)
{
    int data;
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    root = newNode(data);
    printf("enter value of left child of %d:", root->data);
    root->left = create_bt(root->left);
    printf("enter value of right child of %d:", root->data);
    root->right = create_bt(root->right);
}
int main()
{
    Node *root = (Node *)malloc(sizeof(Node));
    root = NULL;
    root = create_bt(root);
    printf("Diameter:%d\n", diameter(root));
    return 0;
}
