#include<stdio.h>
#include<stdlib.h>
#define SIZE 15

void insert(int *a,int *n)
{
    int i,e,p;
    if(*n>SIZE)
    {
        printf("\nOVERFLOWW\n");
        return;
    }
    printf("\nEnter value to insert:");
    scanf("%d",&e);
    printf("\nEnter the position:");
    scanf("%d",&p);
    for(i=*n-1;i>=p-1;i--)
    {
        a[i+1]=a[i];
    }
    a[p-1]=e;
    *n=*n+1;
}

void del(int *a,int *n)
{
    int i,p,e;
    printf("\nEnter the position to delete:");
    scanf("%d",&p);
    e=a[p-1];
    for(i=p-1;i<*n-1;i++)
    {
        a[i]=a[i+1];
    }
    printf("%d is deleted",e);
    *n=*n-1;
}
void display(int *a,int *n)
{
    printf("\nArray\n");
    for(int i=0;i<*n;i++)
    {
        printf("%d  ",a[i]);
    }
}
void main()
{
    int ch,n;
   
    printf("\nEnter number of elements:");
    scanf("%d",&n);
     int a[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nMENU\n1.in\n2.del\n3.dis\n4.exit\n");
    do
    {
    printf("\nEnter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            insert(a,&n);
            break;
        case 2:
            del(a,&n);
            break;
        case 3:
            display(a,&n);
            break;
        case 4:
            exit(0);
        default:
            printf("\nEnter valid choice\n");
    }
    }while(ch!=4);
}

