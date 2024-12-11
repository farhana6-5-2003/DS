#include<stdio.h>
#include<stdlib.h>
void main()
{
 int r,c,m1[10][10],m2[10][10],s[10][10],diff[10][10],choice,y=1,i,j,k,mul[10][10];
 printf("Enter row and column size:");
 scanf("%d%d",&r,&c);
 printf("Enter elements of m1:");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   scanf("%d",&m1[i][j]);
  }
 }
 printf("Enter elements of m2:");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   scanf("%d",&m2[i][j]);
  }
 }
 printf("----MENU-----\n1.Additin\n2.Subtraction\n3.Multiplication\n4.Exit\n");
  do{
 printf("Enter your choice:");
 scanf("%d",&choice);

  switch(choice)
  {
   case 1:
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
        printf("%d  ",s[i][j]);
       }
       printf("\n");
      }
      break;
   case 2:
     for(i=0;i<r;i++)
      {
       for(j=0;j<c;j++)
       {
        diff[i][j]=m1[i][j]-m2[i][j];
       }
      }
      for(i=0;i<r;i++)
      {
       for(j=0;j<c;j++)
       {
        printf("%d  ",diff[i][j]);
       }
       printf("\n");
      }
      break;
   case 3:
     
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            mul[i][j] = 0;
 
            for (int k = 0; k < r; k++) {
                mul[i][j]+= m1[i][k]*m2[k][j];
            }
 
            printf("%d\t", mul[i][j]);
        }
 
        printf("\n");
    }
    break;

   case 4:
      exit(0);
   default:
       printf("Invalid");
     
  }
  printf("Do you want to continue:");
  scanf("%d",&y);
 }while(y!=0);
}

