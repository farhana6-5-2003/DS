#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
int a[11], b[11], res[11];
int U[11]={1,2,3,4,5,6,7,8,9,10};

void display(int bs[]){
for(int i=1;i<11;i++){
printf(" %d ",bs[i]);
}
}
void input(int bs[], int n)
{
int x;
printf("Enter the elements : ");
for(int i=0;i<n;i++){
scanf("%d",&x);
bs[x]=1;
}
}

void set_union(){
for(int i=1;i<11;i++){
res[i]=a[i] | b[i];
}
printf("\nUnion Set : ");
display(res);
}
void set_intersection(){
for(int i=1;i<11;i++){
res[i]=a[i] & b[i];
}
printf("\nIntersection Set : ");
display(res);
}
void set_difference(){
for(int i=1;i<11;i++){
res[i]=a[i] & ~b[i];
}
printf("\nDifference Set : ");
display(res);
}
bool set_equality(){
for(int i=1;i<11;i++){
if(a[i] != b[i]){
return false;
}
}
return true;
}
int main() {
int choice,n1,n2, n;
printf("\nEnter the size of Set1:");
scanf("%d",&n1);
input(a,n1);
printf("\nEnter the size of Set2:");
scanf("%d",&n2);
input(b,n2);
printf("Set Operations Menu:\n");
printf("1. Union of Sets\n");
printf("2. Intersection of Sets\n");
printf("3. Difference of Sets\n");
printf("4. Exit\n");
do {
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) 
{
case 1:
set_union();
break;
case 2:
set_intersection();
break;
case 3:
set_difference();
break;
case 4:
exit(0);
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 4);
return 0;
}
