#include<stdio.h>
#include<stdlib.h>
void 
void main()
{
 int a[20],i,j,n,temp,choice;
 printf("\nEnter number of elements:");
 scanf("%d",&n);
 printf("\nEnter the elements:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("\n-----MENU------\n1.Linear Searcg\n2.Binary Search\n3.Exit\n");
 printf("\nEnter your choice:");
 scanf("%d",&choice); 
 switch(choice)
 {
  case 1:
  	linear(a,n);
        break;
  case 2:
  	binary(a,n);
  	break;
  case 3:
  	exit(0);
 }
}

