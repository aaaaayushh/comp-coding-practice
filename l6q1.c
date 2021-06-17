#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *newNode(int n)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

static int count = 0;
int opcount = 0;
int numNodes(node *root)
{
    opcount++;
    if (root)
    {
        numNodes(root->left);
        count++;
        numNodes(root->right);
    }
    return count;
}

node *create_bt(node *root)
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
    // node *root = (node *)malloc(sizeof(node));
    // root = NULL;
    // root = create_bt(root);
    node *root = newNode(25);
    root->left = newNode(27);
    root->right = newNode(19);
    root->left->left = newNode(17);
    root->left->right = newNode(91);
    root->right->left = newNode(13);
    root->right->right = newNode(55);
    root->left->left->left = newNode(29);
    root->left->left->right = newNode(45);
    root->right->left->left = newNode(34);
    root->right->left->right = newNode(10);
    root->right->right->left = newNode(10);
    root->right->right->right = newNode(10);

    printf("Number of nodes:%d\n", numNodes(root));

    printf("Opcount:%d\n", opcount);
}