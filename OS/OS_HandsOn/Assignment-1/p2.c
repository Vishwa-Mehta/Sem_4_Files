#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	char *x = argv[0];
	char *y = argv[1];
	int sum = atoi(x) + atoi(y);
	printf("Executed p2.c\nNow finding the sum....\n");
	printf("Sum of x and y: %d\n", sum);
	return 0;
}
