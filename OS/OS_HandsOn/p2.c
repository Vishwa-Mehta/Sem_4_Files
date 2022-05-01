#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
	int pid;
	pid = fork();
	if (pid > 0){
		sleep(40);
		printf("the parent process is = %d\n", getpid());
		exit(0);
	}
	else if (pid == 0) {
		printf("the child process is = %d, parent process id = %d\n", getpid(), getppid());
	}
	return 0;
}
