#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void createDLL(struct Node** head, int n) {
    int i, e;
    struct Node* ptr = NULL;
    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &e);
        struct Node* newnode = createNode(e);
        if (*head == NULL) {
            *head = newnode;
            ptr = *head;
        } else {
            ptr->next = newnode;
            newnode->prev = ptr;
            ptr = newnode;
        }
    }
}

void search(struct Node* head, int key) {
    struct Node* ptr = head;
    int position = 1;
    while (ptr != NULL) {
        if (ptr->data == key) {
            printf("\nNode with data %d found at position %d\n", key, position);
            return;
        }
        ptr = ptr->next;
        position++;
    }
    printf("\nNode with data %d not found\n", key);
}

int count(struct Node* head) {
    struct Node* ptr = head;
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void display(struct Node* head) {
    struct Node* ptr = head;
    printf("\nDoubly Linked List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void main() {
    int choice, n, key;
    struct Node* head = NULL;
    
    while (choice!=5) {
        printf("\n----------------------------\n");
        printf("1. Create Doubly Linked List\n2. Search a Node\n3. Number of Nodes\n4.Traverse\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createDLL(&head, n);
                display(head);
                break;
            case 2:
                printf("Enter the data to search: ");
                scanf("%d", &key);
                search(head, key);
                break;
            case 3:
                printf("\nNumber of nodes: %d\n", count(head));
                break;
            case 4:
                    display(head);
                    break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

}

