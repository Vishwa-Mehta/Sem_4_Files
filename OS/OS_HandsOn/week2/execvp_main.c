#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	char *args[]={"./execvp",NULL};
    execvp(args[0],args);
	printf("end of program.\n");
	return 0;
}
