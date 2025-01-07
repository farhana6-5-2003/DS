#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *left, *right;
} *temp, *parent, *ptr;

struct node *createnode(int data)
{
struct node *newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = data;
newnode->left = NULL;
newnode->right = NULL;
return newnode;
}

struct node *insert(struct node *root, int data)
{
if (root == NULL){
return createnode(data);
}
if (data < root->data){
root->left = insert(root->left, data);
}
if (data > root->data){
root->right = insert(root->right, data);
}
return root;
}


void inordertraversal(struct node *root)
{
if (root != NULL){
inordertraversal(root->left);
printf("%d \t", root->data);
inordertraversal(root->right);
}
}


void preordertraversal(struct node *root)
{
if (root != NULL){
printf("%d \t", root->data);
preordertraversal(root->left);
preordertraversal(root->right);
}
}


void postordertraversal(struct node *root)
{
 if (root != NULL)
 {
 postordertraversal(root->left);
 postordertraversal(root->right);
 printf("%d \t", root->data);
 }
}


struct node *succ(struct node *root)
{
temp = root->right;
while (temp->left != NULL)
{
temp = temp->left;
}
return temp;
}


struct node *delete(struct node *root, int data)
{
 if (root == NULL)
 {
 return NULL;
 }
if (data < root->data)
{
root->left = delete (root->left, data);
}
else if (data > root->data)
{
root->right = delete (root->right, data);
}
else{
if (root->left == NULL && root->right == NULL)
{
free(root);
return NULL;
}
else if (root->left == NULL || root->right== NULL)
{
if (root->left == NULL)
{
temp = root->right;
free(root);
return temp;
}
else{
temp = root->left;
free(root);
return temp;
}
}
else{
temp = succ(root);
root->data = temp->data;
root->right = delete (root->right, temp->data);
}
}
return root;
}


int empty(struct node *root)
{
if (root == NULL)
{
printf("Treee is Empty!!");
return 1;
}
else
return 0;
}


int main()
{
struct node *root = NULL;
int data;
int choice, value, s, f;
printf("\n 1. Insert \n 2. Delete \n 3. Inorder Traversal \n 4. Preorder Traversal \n 5. Postorder Traversal \n 6. Exit\n");
do{
printf("\nEnter your choice :");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter your value :");
scanf("%d", &value);
root = insert(root, value);
printf("Value %d inserted into BST :", value);
break;
case 2:
if (!empty(root)){
printf("Enter the Value to delete :");
scanf("%d", &data);
root = delete (root, data); }
break;
case 3:
if(!empty(root))
{
printf("Inorder traversal :");
inordertraversal(root); }
break;
case 4:
if (!empty(root))
{
printf("Preorder traversal :");
preordertraversal(root);}
break;
case 5:
if (!empty(root))
{
printf("Postorder traversal :");
postordertraversal(root);}
break;
case 6:
exit(0);
default:
printf("Invalid Entry !!");
}
}while (choice != 6);
}
