// fork() and wait()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
	pid_t p1;
	p1 = fork();
	int y = 0;
	if (p1 == 0)
		printf("this is a fork example\n");
	else if (p1 < 0)
		printf("failllllllllllll");
	else {
		wait(NULL);
		y++;
		printf("this is the parent process with id = %d\n y = %d\n", y, y);
	}

	return 0;
}
