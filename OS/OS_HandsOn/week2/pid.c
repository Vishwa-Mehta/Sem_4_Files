#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
	pid_t process_id;
	pid_t parent_process_id;
	process_id = getpid();
	parent_process_id = getppid();
	printf("The process id: %d\n",process_id);
	printf("The process id of parent function: %d\n",parent_process_id);
	return 0;
}
