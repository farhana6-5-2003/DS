#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *left, *right, *parent;
char color;
};
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = newNode->right = newNode->parent = NULL;
newNode->color = 'R'; // New nodes are always inserted as Red
return newNode;
}


void leftRotate(struct Node **root, struct Node *x) {
struct Node *y = x->right;
x->right = y->left;
if (y->left != NULL)
y->left->parent = x;
y->parent = x->parent;
if (x->parent == NULL)
*root = y;
else if (x == x->parent->left)
x->parent->left = y;
else
x->parent->right = y;
y->left = x;
x->parent = y;
}


void rightRotate(struct Node **root, struct Node *x) {
struct Node *y = x->left;
x->left = y->right;
if (y->right != NULL)
y->right->parent = x;
y->parent = x->parent;
if (x->parent == NULL)
*root = y;
else if (x == x->parent->right)
x->parent->right = y;
else
x->parent->left = y;
y->right = x;
x->parent = y;
}

void fixViolation(struct Node **root, struct Node *z) 
{
    while (z != *root && z->parent->color == 'R') 
    {
        if (z->parent == z->parent->parent->left) 
        {
            struct Node *y = z->parent->parent->right;
            if (y != NULL && y->color == 'R') 
            {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } 
            else 
            {
                if (z == z->parent->right) 
                {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rightRotate(root, z->parent->parent);
            }
        } 
        else 
        {
            struct Node *y = z->parent->parent->left;
            if (y != NULL && y->color == 'R') 
            {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } 
            else 
            {
                if (z == z->parent->left) 
                {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = 'B';
}


void insert(struct Node **root, int data) {
struct Node *z = createNode(data);
struct Node *y = NULL;
struct Node *x = *root;
while (x != NULL) {
y = x;
if (z->data < x->data)
x = x->left;
else
 x = x->right;
}
z->parent = y;
if (y == NULL)
*root = z;
else if (z->data < y->data)
y->left = z;
else
y->right = z;
fixViolation(root, z);
}


void inorderTraversal(struct Node *root) {
if (root == NULL)
return;
inorderTraversal(root->left);
printf("%d(%c) ", root->data, root->color);
inorderTraversal(root->right);
}


int main() {
struct Node *root = NULL;
int choice, value;
printf("\nMenu:\n");
printf("1. Insert a new node\n");
printf("2. Left rotate\n");
printf("3. Right rotate\n");
printf("4. Inorder traversal\n");
printf("5. Exit\n");
do {
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to insert: ");
scanf("%d", &value);
insert(&root, value);
printf("Value %d inserted.\n", value);
break;
case 2:
printf("Enter value to left rotate: ");
scanf("%d", &value);
struct Node *x1 = root;
while (x1 != NULL && x1->data != value) {
if (value < x1->data)
x1 = x1->left;
else
 x1 = x1->right;
}
if (x1 != NULL) {
leftRotate(&root, x1);
printf("Left rotation performed on node with value %d.\n", value);
} else {
printf("Node with value %d not found.\n", value);
}
break;
case 3:
printf("Enter value to right rotate: ");
scanf("%d", &value);
struct Node *x2 = root;
while (x2 != NULL && x2->data != value) {
if (value < x2->data)
x2 = x2->left;
else
x2 = x2->right;
}
if (x2 != NULL) {
rightRotate(&root, x2);
printf("Right rotation performed on node with value %d.\n", value);
} else {
printf("Node with value %d not found.\n", value);
}
break;
case 4:
printf("Inorder traversal: ");
inorderTraversal(root);
printf("\n");
break;
case 5:
exit(0);
default:
printf("Invalid choice. Please try again.\n");
}
}while(choice!=5);
return 0;
}
