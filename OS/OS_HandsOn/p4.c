#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
	fork();
	if (fork() && fork()) {
		fork();
	}
		printf("abccc\n");
	return 0;
}
