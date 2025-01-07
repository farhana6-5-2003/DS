#include<stdio.h>
void main()
{
 int a[20],i,j,n,temp;
 printf("Enter number of elements:");
 scanf("%d",&n);
 printf("\nEnter Elements :");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("\nArray before Sorting:\n");
 for(i=0;i<n;i++)
 {
  printf("%d ",a[i]);
 }
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 printf("\nArray After Sorting:\n");
 for(i=0;i<n;i++)
 {
  printf("%d ",a[i]);
 }
 printf("\n");
}
