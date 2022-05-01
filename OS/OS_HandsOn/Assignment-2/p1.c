// Using pipes concatenate 2 strings
// one process takes in the string as input and writes it to the pipe
// 2nd process reads from pipe and concatenates it with other string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int fd1[2];
	int fd2[2];
	pid_t p;

	if (pipe(fd1) == -1) {
		fprintf(stderr, "pipe failed");
		return 1;
	}
	if (pipe(fd2) == -1) {
		fprintf(stderr, "pipe failed");
		return 1;
	}

	char str1[100];
	printf("enter string 1: ");
	scanf("%s", str1);
	char str2[100];
	printf("enter string 2: ");
	scanf("%s", str2);
	p = fork();
	if (p < 0) {
		fprintf(stderr, "fork failed");
		return 1;
	}
	else if (p > 0) {
		char str3[100];
		close(fd1[0]);
		write(fd1[1], str1, strlen(str1) + 1);
		close(fd1[1]);
		wait(NULL);
		close(fd2[1]);
		read(fd2[0], str3, 100);
		printf("Concatenated string: %s\n", str3);
		close(fd2[0]);
	}
	else {
		close(fd1[1]);
		char str3[100];
		read(fd1[0], str3, 100);
		int k = strlen(str3);
		int i;
		for (i = 0; i < strlen(str2); i++)
			str3[k++] = str2[i];
		str3[k] = '\0';
		close(fd1[0]);
		close(fd2[0]);
		write(fd2[1], str3, strlen(str3) + 1);
		close(fd2[1]);
		exit(0);
	}
}
