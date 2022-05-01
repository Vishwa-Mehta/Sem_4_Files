// write a program that accepts 2 integers x and y. Now use exec to execute another user defined program that prints the sum of x and y.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
	printf("This is p1.c\n");
	char x[100], y[100];
	printf("Enter x: ");
	scanf("%s", x);
	printf("Enter y: ");
	scanf("%s", y);
	char* s[] = {x, y, NULL};
	printf("Calling p2.c to calc sum....\n");
	execv("./p2", s);
}
