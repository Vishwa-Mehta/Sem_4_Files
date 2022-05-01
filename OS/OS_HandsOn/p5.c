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
	int fd2; //file descriptor
	char buff[BUFFER_SIZE] = "";
	//char buff1[BUFFER_SIZE] = "hello";
	char myfifo[BUFFER_SIZE] = "/mnt/c/Users/Vishwa/Documents/Vishwa_PES/Sem4/OS/OS_HandsOn/abc.txt";
	//char myfifo1[BUFFER_SIZE] = "/mnt/c/Users/Vishwa/Documents/Vishwa_PES/Sem4/OS/OS_HandsOn/xyz.txt";
	mkfifo(myfifo, 0666);
	//mkfifo(myfifo1, 0666);
	fd1 = open(myfifo, O_RDONLY);
	//fd2 = open(myfifo1, 1);
	read(fd1, buff, BUFFER_SIZE);
	//write(fd2, buff1, strlen(buff1));
	printf("content read is %s\n", buff);
	close(fd1);
	//close(fd2);
	return 0;
}
