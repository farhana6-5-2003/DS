#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
void main()
{
 struct node *head=NULL;
 struct node *ptr=NULL;
 int n,i,e;
 printf("\nEnter the number of elements:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the data for node %d:",i+1);
  scanf("%d",&e);
  newnode->data=e;
  newnode->next=NULL;
  if(head==NULL)
  {
   head=newnode;
  }
  else
  {
   ptr->next=newnode;
  }
  ptr=newnode;
 }
 
 ptr=head;
 printf("\nLinked List:\n");
 while(ptr!=NULL)
 {
  printf(" %d ->",ptr->data);
  ptr=ptr->next;
 }
 printf(" NULL\n");
}
