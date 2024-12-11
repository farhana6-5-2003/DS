#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
 struct Node *newnode=malloc(sizeof(struct Node));
 newnode->data=data;
 newnode->next=NULL;
 return newnode; 
}

void insertbeg(struct Node **head,int data)
{
 struct Node *newnode=createNode(data);
 newnode->next=*head;
 *head=newnode;
}

void insertend(struct Node **head,int data)
{ 
 struct Node *newnode=createNode(data);
 struct Node *ptr=*head;
 if(*head==NULL)
 {
  *head=newnode;
 
 }
 while(ptr->next!=NULL)
 {
  ptr=ptr->next;
 }
 ptr->next=newnode;
}

void traverse(struct Node *ptr)
{
 while(ptr!=NULL)
 {
  printf(" %d->",ptr->data);
  ptr=ptr->next;
 }
 printf("NULL\n");
}

void main()
{
 int n,e,i,choice,data;
 struct Node *head=NULL;
 struct Node *ptr=NULL;
 printf("\nEnter number of elements:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("\nEnter data for node %d:",i+1);
  scanf("%d",&e);
   struct Node *newnode=createNode(e);
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
    printf("\nMenu:");
    printf("\n1. Insert at beginning");
    printf("\n2. Insert after a node");
    printf("\n3. Append to end");
    printf("\n4. Search for a node");
    printf("\n5. Print the list");
    printf("\n6. Exit");
    do{
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1:
     		printf("Enter data to insert at beginning:");
     		scanf("%d",&data);
     		insertbeg(&head,data);
     		break;
     case 3:
     		printf("Enter data to insert at end:");
     		scanf("%d",&data);
     		insertend(&head,data);
     		break;
     case 5:
     		traverse(head);
     		break;
     default:
     		printf("Invalid");
    }
    
    
    
    }while(choice!=6);
}
