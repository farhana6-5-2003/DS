#include<stdio.h>
#include<stdlib.h>
int n;
void insert(int a[10],int *n,int e,int p)
{
    int i;
    *n=*n+1;
   for(i=*n-1;i>=p;i--)
   {
       a[i]=a[i-1];
   }
   a[p-1]=e;
  
}
void delete(int a[10],int *n,int p)
{
    int i;
    
    for(i=p-1;i<*n-1;i++)
    {
        a[i]=a[i+1];
    }
    *n=*n-1;
}
void display(int a[10],int *n)
{
    for(int i=0;i<*n;i++)
    {
        printf("%d   ",a[i]);
    }
}
void main()
{
    int a[10],i,e,p,ch;
    printf("\nEnter n:");
    scanf("%d",&n);
    printf("\nEnter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n1.Insert 2.delete\n3.Traverse\n4.Exit");
    do{
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
                printf("\nEnter the element to insert:");
                scanf("%d",&e);
                printf("\nEnter the position to insert:");
                scanf("%d",&p);
                insert(a,&n,e,p);
                break;
        case 2:
                printf("\nEnter the position of element to delete:");
                scanf("%d",&p);
                delete(a,&n,p);
                break;
        case 3:
               display(a,&n);
               break;
        case 4:
                printf("\nExiting....");
                exit(0);
        default:
                printf("\nInvalid");
                
    }
    }while(ch!=4);
}
