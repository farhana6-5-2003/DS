#include<stdio.h>
#include<stdlib.h>
void sum1();
void sum2(int,int);
int sum3();
int sum4(int,int);
void main(){
int a,b,res,j,ch;
do{
j=1;
printf("\nMENU");
printf("\n1.Function without argument and return type\n2.Function with argument and no return type\n3.Function without argument and with returntype\n4.Function with argument and return type\n5.Exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
if(ch==2 || ch==4)
{
printf("Enter two numbers:");
scanf("%d%d",&a,&b);
}
switch(ch){
case 1:
sum1();
break;
case 2:
sum2(a,b);
break;
case 3:
res=sum3();
printf("\nSum is %d",res);
break;
case 4:
res=sum4(a,b);
printf("\nSum is %d",res);
break;
case 5:
exit(0);
break;
default:
printf("Invalid choice. Please enter value from 1 to 5");
break;
}
}while(j<=4);
}
void sum1()
{
int a,b;
printf("\nEnter two numbers:");
scanf("%d%d",&a,&b);
printf("\nSum is %d",a+b);
}
void sum2(int a,int b)
{
printf("\nSum is %d",a+b);
}
int sum3()
{
int a,b;
printf("\nEnter two numbers:");
scanf("%d%d",&a,&b);
return a+b;
}
int sum4(int a, int b)
{
return a+b;
}
