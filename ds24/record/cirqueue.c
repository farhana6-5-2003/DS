#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int que[MAX];
int front=0;
int rear=0;
int count=0;
void en(int value)
{
    if(count==MAX-1)
    {
        printf("\noverflow");
        return;
    }
    que[rear]=value;
    rear=(rear+1)%MAX;
    count+=1;
}
void de()
{
if(count==0)
   {
       printf("\nEmpty");
       return;
   }
  printf("%d is deleted\n",que[front]);
  front=(front+1)%MAX;
}

void display()
{
   if(count==0)
   {
       printf("\nEmpty");
       return;
   }
   for(int i=0;i<count;i++)
   {
       printf("%d  ",que[(front+i)%MAX]);
   }
}
void main()
{
    int ch,value;
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
              printf("\nEnter the value to insert:");
              scanf("%d",&value);
              en(value);
              break;
        case 2:
              de();
              break;
        case 3:
              display();
              break;
        case 4:
              exit(0);
        default:
              printf("\nInvalid choice");
        }
    }while(ch!=4);
}
