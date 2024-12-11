#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void deleteBeg(struct Node** head, int data) {
    struct Node *ptr;
    if(*head==NULL)
    {
     printf("\nLinked List is Empty\n");
     exit(0);
    }
    ptr=*head;
    *head=*head->next;
    printf("\nDeleted Node is %d\n",ptr->data);
    free(ptr);
    
}


void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* new_node = createNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}


void deleteEnd(struct Node** head, int data)
 {
    struct Node *ptr = *head;
    if (*head == NULL) 
    {
     printf("\nLinked List is Empty\n");
     exit(0);
    }
    if(*head->next==NULL)
    {
     printf("\nDeleted node is %d",*head->data);
     *head=NULL;
     free(head);
    }
 else{
    ptr=*head;
    while(ptr->next != NULL) {
        ptr1=ptr;
        ptr = ptr->next;
    }

    last->next = new_node;
}
}

int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}


void printList(struct Node *node) {
    while (node != NULL) {
        printf(" %d ->", node->data);
        node = node->next;
    }
    printf(" NULL\n");
}


void createLinkedList(struct Node** head_ref) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        append(head_ref, data);
    }
}


void displayMenu() {
    printf("\nMenu:");
    printf("\n1. Delete from beginning");
    printf("\n2. Delete from End");
    printf("\n3. Delete from a particular location");
    printf("\n4. Traverse");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    printf("Creating a linked list:\n");
    createLinkedList(&head);

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter node to delete:");
                scanf("%d",&data);
                deleteBeg(&head, data);
                break;
                
            case 2:
                printf("\nEnter node to delete:");
                scanf("%d",&data);
                deleteEnd(&head,data);
                break;
                
            case 3:
                printf("\nEnter data to append to end: ");
                scanf("%d", &data);
                append(&head, data);
                break;
           
            case 4:
                printf("\nLinked list: ");
                printList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}

