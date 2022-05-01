#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

//parent process writes
//child process reads the written content

int main() {
	char write_msg[BUFFER_SIZE] = "Greetings";
	char read_msg[BUFFER_SIZE] = "";
	int fd[2];

	return 0;
}
