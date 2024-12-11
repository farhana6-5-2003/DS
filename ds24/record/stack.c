#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
if (top == MAX - 1) {
printf("Stack Overflow!");
} else {
top++;
stack[top] = value;
printf("%d pushed onto the stack.\n", value);
}
}
void pop() {
if (top == -1) {
printf("Stack Underflow!.\n");
} else {
printf("%d popped from the stack.\n", stack[top]);
top--;
}
}
void display() {
if (top ==-1)
{
printf("The stack is empty.\n");
} else {
printf("Stack elements are:\n");
for (int i = top; i >= 0; i--) {
printf("%d\n", stack[i]);
}
}
}
int main() {
int choice, value;
printf("Stack Operations using Arrays\n");
printf("------------------------------------\n");
printf("\nChoose an operation:\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Display\n");
printf("4. Exit\n");
do{
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to push: ");
scanf("%d", &value);
push(value);
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
printf("Exiting...\n");
return 0;
default:
printf("Invalid choice! Please try again.\n");
}
}while(choice!=4);
return 0;
}

