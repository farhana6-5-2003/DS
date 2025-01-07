#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#define MIN 2
struct BTreeNode {
int items[MAX + 1], count;
struct BTreeNode *links[MAX + 1];
};

struct BTreeNode *root;

struct BTreeNode *createNode(int item, struct BTreeNode *child) 
{
struct BTreeNode *newNode;
newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
newNode->items[1] = item;
newNode->count = 1;
newNode->links[0] = root;
newNode->links[1] = child;
return newNode;
}

void insertNode(int item, int pos, struct BTreeNode *node, struct BTreeNode *child) {
int j = node->count;
while (j > pos) {
node->items[j + 1] = node->items[j];
node->links[j + 1] = node->links[j];
j--;
}
node->items[j + 1] = item;
node->links[j + 1] = child;
node->count++;
}
void splitNode(int item, int *pval, int pos, struct BTreeNode *node, struct BTreeNode *child, struct BTreeNode **newNode) {
int median, j;
if (pos > MIN)
median = MIN + 1;
else
median = MIN;
*newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
j = median + 1;
while (j <= MAX) {
(*newNode)->items[j - median] = node->items[j];
(*newNode)->links[j - median] = node->links[j];
j++;
}
node->count = median;
(*newNode)->count = MAX - median;
if (pos <= MIN)
insertNode(item, pos, node, child);
else
insertNode(item, pos - median, *newNode, child);
*pval = node->items[node->count];
(*newNode)->links[0] = node->links[node->count];
node->count--;
}
int setValue(int item, int *pval, struct BTreeNode *node, struct BTreeNode
**child) {
int pos;
if (!node) {
*pval = item;
*child = NULL;
return 1;
}
if (item < node->items[1]) {
pos = 0;
} else {
for (pos = node->count;
(item < node->items[pos] && pos > 1); pos--)
;
if (item == node->items[pos]) {
return 0;
}
}
if (setValue(item, pval, node->links[pos], child)) {
if (node->count < MAX) {
insertNode(*pval, pos, node, *child);
} else {
splitNode(*pval, pval, pos, node, *child, child);
return 1;
}
}
return 0;}
void insert(int item) {
int flag, i;
struct BTreeNode *child;
flag = setValue(item, &i, root, &child);
if (flag)
root = createNode(i, child);
}
void search(int item, int *pos, struct BTreeNode *node) {
if (!node) {
return;
}
if (item < node->items[1]) {
*pos = 0;
} else {
for (*pos = node->count;(item < node->items[*pos] && *pos > 1); (*pos)--) ;
if (item == node->items[*pos]) {
printf("%d found\n", item);
return;
}
}
search(item, pos, node->links[*pos]);
return;
}
void inorder(struct BTreeNode *node) {
int i;
if (node) {
for (i = 0; i < node->count; i++) {
inorder(node->links[i]);
printf("%d ", node->items[i + 1]);
}
inorder(node->links[i]);
}
}
int main() {
int item, ch;
printf("1. Insertion\n");
printf("2. Searching\n");
printf("3. Inorder Traversal\n");
printf("4. Exit\n");
do {
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
printf("Enter the item to insert: ");
scanf("%d", &item);
insert(item);
break;
case 2:
printf("Enter the item to search: ");
scanf("%d", &item);
search(item, &ch, root);
break;
case 3:
inorder(root);
printf("\n");
break;
case 4:
exit(0);
default:
printf("Invalid choice\n");
}
}while(ch!=4);
}
