// implementation of FIFO
// named pipes
// ps -aux | grep "chrome"
// pipe is a one way channel
#include <stdio.h>
#include <unistd.h> // file path
#include <fcntl.h> // file control
#include <string.h>
#include <sys/types.h> // data types for FIFO
#include <sys/stat.h> // mkfifo
#define BUFFER_SIZE 200
int main() {
	int fd1; //file descriptor
	char buff[BUFFER_SIZE] = "This proly works.\n";
	char myfifo[BUFFER_SIZE] = "/mnt/c/Users/Vishwa/Documents/Vishwa_PES/Sem4/OS/OS_HandsOn/xyz.txt";
	mkfifo(myfifo, 0666);
	fd1 = open(myfifo, O_WRONLY);
	write(fd1, buff, BUFFER_SIZE);
	printf("content is written in xyz.txt\n");
	close(fd1);
	return 0;
}
