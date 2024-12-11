#include<stdio.h>
#include<stdlib.h>
//void add(int*,int,int);
/*void sub(int*,int,int);
void mul(int*,int,int);*/
void main()
{
 int r,c,m1[10][10],m2[10][10],i,j,choice,chh=1,s[10][10];
 printf("Enter row size:");
 scanf("%d",&r);
 printf("Enter column size:");
 scanf("%d",&c);
 printf("\nEnter elements of matrix1:");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   scanf("%d",&m1[i][j]);
  }
 }
 printf("\nEnter elements of matrix2:");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   scanf("%d",&m2[i][j]);
  }
 }
 printf("\n-------MENU----------\n");
 printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Exit\n");
 printf("\nEnter your choice:");
 scanf("%d",&choice);
 do{
 switch(choice)
 {
  case 1:
     // add(mat,m,n);
     for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   s[i][j]=m1[i][j]+m2[i][j];
  }
 }
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%d ",s[i][j]);
  }
  printf("\n");
 }
     
      break;
  /*case 2:
       sub(mat,m,n);
       break;
  case 3 :
       mul(mat,m,n);
       break;*/
  case 4:
       exit(0);
  default:
         printf("\nInvalid choice");
  }
 }while(chh!=0);
}



/*void add(int *mat,int m,int n)
{
 int i,j,sum=0;
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   sum=sum+mat[i][j];
  }
 }
}*/
