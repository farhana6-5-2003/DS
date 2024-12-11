#include<stdio.h>
#include<stdlib.h>
void insert(int*,int);
void delete(int*,int);
void traverse(int*,int);
void main()
{
 int a[20],n,i,choice,c=1;
 printf("Enter size of the array:");
 scanf("%d",&n);
 printf("Enter the elements:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 do{
 printf("\n--------MENU----------\n");
 printf("1.Insert an element to a particular position\n2.Delete an element from a particular position\n3.Traverse\n4.Exit\n");
 printf("\nEnter your choice:");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
        insert(a,n);
        break;
  case 2:
        delete(a,n);
        break;
  case 3:
        traverse(a,n);
        break;
  case 4:
        exit(0);      
 
  default:
         printf("\nInalid Entry\n");
 }
 printf("\nDo you want to continue(0/1):");
 scanf("%d",&c);
 }while(c!=0);
}
void insert(int *arr,int size)
{
 int e,p,i;
 if(size>20)
 {
  printf("Overflow");
  exit(0);
 }
 printf("\nEnter the element to insert:");
 scanf("%d",&e);
 printf("\nEnter the position:");
 scanf("%d",&p);
 for(i=size-1;i>=p;i--)
 {
  arr[i+1]=arr[i];
 }
 arr[p]=e;
 printf("\nElement inserted at index %d\n",p);
 size++;
 printf("\nNew array\n");
 traverse(arr,size);
}
void delete(int *arr,int size)
{
 int p,i,e;
 if(size<0)
 {
  printf("Array is Empty");
 }
 else
 {
  printf("\nEnter the position to delete:");
  scanf("%d",&p);
  e=arr[p-1];
  for(i=p-1;i<size;i++)
  {
   arr[i]=arr[i+1];
  }
  //size=size-1;
  printf("\nDeleted Element is %d\n",e);
  printf("\nNew array\n");
  traverse(arr,size);
 }
}

void traverse(int *arr,int size)
{
 int i;
 for(i=0;i<size;i++)
 {
  printf("%d  ",arr[i]);
 }
}
