#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
	char *args[]={"./execv",NULL};
    execv(args[0],args);
	printf("end of program.\n");
	return 0;
}
