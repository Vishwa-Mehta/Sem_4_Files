#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
	if (fork() == 0) {
        printf("this is a child process\n");
	}
	else {
        printf("this is the parent process\n");
		wait(NULL);
        printf("child process has terminated\n");
    }
    printf("end of program\n");
	return 0;
}
