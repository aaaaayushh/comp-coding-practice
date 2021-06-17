#include <stdio.h>
#include <stdlib.h>
typedef struct node{
int data;
struct node *left;
struct node *right;
}NODE;
NODE* create(int val){
NODE* temp = (NODE*)malloc(sizeof(NODE));
temp->data = val;
temp->left = temp->right = NULL;
return temp;
}
NODE* insert(NODE* cur, int key){
if(cur == NULL){
return create(key);
}
if(key == cur->data){
printf("Key Found\n");
}
else if(key < cur->data){
cur->left = insert(cur->left, key);
}
else{
cur->right = insert(cur->right, key);
}
return cur;
}
void inorder(NODE* root){
if(root){
inorder(root->left);
printf("%d ", root->data);inorder(root->right);
}
}
void preorder(NODE* root){
if(root){
printf("%d",root->data);
preorder(root->left);
preorder(root->right);
}
}
void postorder(NODE* root){
if(root){
postorder(root->left);
postorder(root->right);
printf("%d",root->data);
}
}
int menu(){
printf("\nMenu\n");
printf("1. Insert\n");
printf("2. Inorder\n");
printf("3. Preorder\n");
printf("4. Postorder\n");
printf("5. Search\n");
printf("6. Exit\n");
printf("Enter Your choice: ");
int choice;
scanf("%d", &choice);
return choice;
}
int main(){
NODE* root = NULL;
int choice;
do{
choice = menu();
if(choice == 1){
int val;
printf("Enter Number to be inserted: ");
scanf("%d", &val);
root = insert(root, val);
}
else if(choice == 2){
printf("Inorder List is:\n");
inorder(root);
printf("\n");
}
else if(choice == 3){printf("Preorder List is:\n");
preorder(root);
printf("\n");
}
else if(choice == 4){
printf("Postorder List is:\n");
postorder(root);
printf("\n");
}
else if(choice == 5){
printf("Enter key to be searched:");
int key;
scanf("%d",&key);
root = insert(root,key);
}
}while(choice != 6);
}