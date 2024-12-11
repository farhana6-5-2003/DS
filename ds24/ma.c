#include<stdio.h>
void main()
{
 int m1[10][10],m2[10][10],s[10][10],i,j,r,c;
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
}
