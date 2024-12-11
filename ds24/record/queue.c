#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void enqueue(int);
void dequeue();
void display();
int queue[MAX];
int rear=-1;
int front=-1;
void main()
{
  int choice,value;
  printf("-----MENU-----");
  printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
  do{
  printf("\nEnter your choice:");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:
       printf("\nEnter the value to insert:");
       scanf("%d",&value);
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
  }while(choice!=4);
  
}

void enqueue(int value)
{
 if(rear==MAX-1)
 {
  printf("\nQueue Overflow!!!\n");
 }
 else{
 if(front==-1)
 {
  front=0;
 }
 rear=rear+1;
 queue[rear]=value;
 printf("\n%d is  inserted\n",value);
}
}

void dequeue()
{
 if(front==rear+1)
 {
  printf("\nQueue is Empty!!!!\n");
  
 }
 else{
 printf("\nElement deleted is %d",queue[front]);
 front=front+1;
 }
}

void display()
{
 int i;
 if(front == - 1)
     printf("Queue is empty \n");
 else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");

    }
}
