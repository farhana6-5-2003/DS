#include <stdio.h>
#include <stdlib.h>
#define MAX 6

void enqueue(int);
void dequeue();
void display();

int cqueue[MAX];
int rear = -1;
int front = -1;

void main() {
    int choice, value;
    printf("-----MENU-----");
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do {
        printf("\n\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert:");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice");
        }
    } while (choice != 4);
}

void enqueue(int value) 
{
    if((front==0 && rear==MAX-1) || (rear == (front-1)%(MAX-1))) 
    {
        printf("\nQueue Overflow!!!\n");
        return;
    } 
    else if (front == -1) 
    { 
        front=rear=0;
        cqueue[rear]=value;
    } 
    else if(rear == MAX-1 && front!=0)
     {
        rear=0;
        cqueue[rear]=value;
    } 
    else 
    {
        rear=(rear+1)%MAX;
        cqueue[rear]=value;
    }
    printf("\n%d is inserted\n", value);
}

void dequeue() 
{
    if (front == -1) 
    {
        printf("\nQueue is Empty!!!!\n");
        return;
    }

    printf("\nElement deleted is %d\n", cqueue[front]);

    if (front == rear)
     {
        front=rear=-1;
    } 
    else if (front == MAX - 1) 
    {
        front=0;
    } 
    else 
    {
        front=front + 1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty \n");
        return;
    }

    printf("Queue is : \n");
    if (rear >= front) {
        for (int i=front;i<=rear;i++)
            printf("%d ", cqueue[i]);
    } 
    else 
    {
        for (int i=front;i<MAX;i++)
            printf("%d ", cqueue[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    printf("\n");
}

