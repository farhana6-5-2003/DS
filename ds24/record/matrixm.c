#include <stdio.h>
#include<stdlib.h>
#define MAX 10
void input(int mat[MAX][MAX],int r,int c) {
for (int i = 0; i < r; i++) {
for (int j = 0; j < c; j++) {
scanf("%d", &mat[i][j]);
}
}
}
void display(int mat[MAX][MAX], int r, int c) {
for (int i = 0; i < r; i++) {
for (int j = 0; j < c; j++) {
printf("%d ", mat[i][j]);
}
printf("\n");
}}
void add(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
int r, int c) {
for (int i = 0; i < r; i++) {
for (int j = 0; j < c; j++) {
result[i][j] = a[i][j] + b[i][j];
}
}
}
void sub(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int
r,int c) {
for (int i = 0; i < r; i++) {
for (int j = 0; j < c; j++) {
result[i][j] = a[i][j]-b[i][j];
}
}
}
void mul(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
int r1, int c1, int c2) {
for (int i = 0; i < r1; i++) {
for (int j = 0; j < c2; j++) {
result[i][j] = 0;
for (int k = 0; k < c1; k++) {
result[i][j] += a[i][k] * b[k][j];
}
}
}
}
void main() {
int m1[MAX][MAX],m2[MAX][MAX], result[MAX][MAX];
int r1,c1,r2,c2,choice;
printf("Enter rows and columns for the first matrix: ");
scanf("%d%d", &r1, &c1);
printf("Enter rows and columns for the second matrix: ");
scanf("%d%d", &r2, &c2);
printf("Enter elements of the first matrix:\n");
input(m1,r1,c1);
printf("Enter elements of the second matrix:\n");
input(m2,r2,c2);
printf("\nMENU\n");
printf("1. Addition\n");
printf("2. Subtraction\n");
printf("3. Multiplication\n");
printf("4. Exit\n");
do{
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
if (r1==r2 && c1==c2) {
add(m1,m2,result,r1,c1);
printf("Matrix addition result:\n");
display(result,r1,c1);
} else {
printf("Matrix addition not possible.\n");
}
break;
case 2:
if (r1==r2 && c1==c2) {
sub(m1,m2,result,r1,c1);
printf("Matrix subtraction result:\n");
display(result,r1,c1);
} else {
printf("Matrix subtraction not possible.\n");
}
break;
case 3:
if (c1==r2) {
mul(m1,m2,result,r1,c1,c2);
printf("Matrix multiplication result:\n");
display(result,r1,c2);
}
else {
printf("Matrix multiplication not possible.\n");
}
break;
case 4:
exit(0);
default:
printf("Invalid choice! Please select a valid operation.\n");
}
}while(choice!=4);
}
