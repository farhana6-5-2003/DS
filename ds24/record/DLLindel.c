#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
struct Node* prev;
};
struct Node* createNode(int data)
{
struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
new_node->data = data;
new_node->next = NULL;
new_node->prev = NULL;
return new_node;
}
void insertAtBeginning(struct Node** head_ref, int new_data) {
struct Node* new_node = createNode(new_data);
new_node->next = (*head_ref);
if ((*head_ref) != NULL) {
(*head_ref)->prev = new_node;
}
(*head_ref) = new_node;
}
void insertAtEnd(struct Node** head_ref, int new_data) {
struct Node* new_node = createNode(new_data);
struct Node* last = *head_ref;
if (*head_ref == NULL) {
*head_ref = new_node;
return;
}
while (last->next != NULL) {
last = last->next;
}
last->next = new_node;
new_node->prev = last;
}
void deleteFromBeginning(struct Node** head_ref) {
if (*head_ref == NULL) {
printf("\nList is empty.\n");
return;
}
struct Node* temp = *head_ref;
*head_ref = (*head_ref)->next;
if (*head_ref != NULL) {
(*head_ref)->prev = NULL;
}
printf("\n%d deleted from the beginning.\n",temp->data);
free(temp);
}
void deleteFromEnd(struct Node** head_ref) 
{
if (*head_ref == NULL) 
  {
  printf("\nList is empty.\n");
  return;
  }
struct Node* last = *head_ref;
if (last->next == NULL) {
*head_ref = NULL;
}
else {
while (last->next != NULL) {
last = last->next;
}
last->prev->next = NULL;
}
printf("\n%d deleted from the beginning.\n",last->data);
free(last);
}

void traverse(struct Node* node) {
struct Node* last;
while (node != NULL) {
printf(" %d <->", node->data);
last = node;
node = node->next;
}
printf(" NULL\n");
}

int main() {
struct Node* head = NULL;
int n, e, i, choice, data;
printf("\nEnter number of elements:");
scanf("%d", &n);
for (i = 0; i < n; i++) {
printf("\nEnter data for node %d:", i + 1);
scanf("%d", &e);
insertAtEnd(&head, e);
}
printf("\nMenu:");
printf("\n1. Insert at beginning");
printf("\n2. Insert at end");
printf("\n3. Delete from beginning");
printf("\n4. Delete from end");
printf("\n5. Print the list ");
printf("\n6. Exit");
do {
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to insert at beginning:");
scanf("%d", &data);
insertAtBeginning(&head, data);
break;
case 2:
printf("Enter data to insert at end:");
scanf("%d", &data);
insertAtEnd(&head, data);
break;
case 3:
deleteFromBeginning(&head);
break;
case 4:
deleteFromEnd(&head);
break;
case 5:
printf("\nDoubly linked list: ");
traverse(head);
break;
case 6:
exit(0);
default:
printf("Invalid choice\n");
}
} while (choice != 6);
return 0;
}
