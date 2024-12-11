#include<stdio.h>
void main()
{
 int m,n,i,j,mat[10][10],mat2[10][10],sum[10][10];
 printf("Enter row size:");
 scanf("%d",&m);
 printf("Enter column size:");
 scanf("%d",&n);
 printf("Enter elements:");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&mat[i][j]);
  }
 }
 printf("Enter elements:");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&mat2[i][j]);
  }
 }
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;i++)
  {
   sum[i][j]=mat[i][j]+mat2[i][j];
  }
 }
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   printf("%d ",sum[i][j]);
  }
  printf("\n");
 }
}
