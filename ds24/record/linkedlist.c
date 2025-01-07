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

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
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


void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node *last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}


int search(struct Node* head, int key) {
    struct Node* current = head;
    int count=0;
    while (current != NULL) {
        if (current->data == key) {
            printf("\nFound at position %d",count+1);
            return 1;
        }
        current = current->next;
        count=count+1;
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
    printf("\n1. Insert at beginning");
    printf("\n2. Insert after a node");
    printf("\n3. Append to end");
    printf("\n4. Search for a node");
    printf("\n5. Print the list");
    printf("\n6. Exit");
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
                printf("\nEnter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("\nEnter data to insert after a node: ");
                scanf("%d", &data);
                printf("\nEnter key of node after which to insert: ");
                scanf("%d", &key);
                struct Node* prev_node = head;
                while (prev_node != NULL && prev_node->data != key) {
                    prev_node = prev_node->next;
                }
                insertAfter(prev_node, data);
                break;
            case 3:
                printf("\nEnter data to append to end: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 4:
                printf("\nEnter data to search for: ");
                scanf("%d", &key);
                if (search(head, key)) {
                    printf("\nItem %d found in the list\n\n", key);
                } else {
                    printf("\nItem %d not found in the list\n",key);
                }
                break;
            case 5:
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

