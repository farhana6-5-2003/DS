#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int isEmpty(struct Node* top) {
    return !top;
}


void push(struct Node** top, int new_data) {
    struct Node* newNode = createNode(new_data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto the stack.\n", new_data);
}


void pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow!.\n");
        return;
    }
    struct Node* temp = *top;
    printf("%d popped from the stack.\n", temp->data);
    *top = (*top)->next;
    free(temp);
}


void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("The stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* top = NULL;
    int choice, value;

    printf("Stack Operations using Linked List\n");
    printf("------------------------------------\n");
    printf("\nChoose an operation:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

