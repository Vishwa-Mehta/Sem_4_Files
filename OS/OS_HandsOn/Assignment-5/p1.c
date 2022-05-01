// wap a c program to change permissions of files in a directory created after a certain date.
// inputs: dir, date, new permission -- runtime args

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include<dirent.h>
#include<string.h>

int main (int argc, char **argv) {
    if(argc != 6) {
        printf("Format Error! \n ");
        printf("Follow the following format : ./executable.out /full/absolute/path/ DD MM YYYY nnnn\n");
        printf("Note that the / after full path is ver important");
		printf("Enter permissions in form of a 4 digit integers each from 0-7\nFor example:\n 0777 or 0767");
        return 0;
    }
    
	int day = atoi(argv[2]);
    int mon = atoi(argv[3]);
    int yer = atoi(argv[4]);
    
	struct stat attrib;
    DIR* d = opendir(argv[1]);
    struct dirent* filefo_path;
	char mode[4];
	strcpy(mode, argv[5]);
	int i;
    i = strtol(mode, 0, 8);

    while((filefo_path = readdir(d)) != NULL) {
        char temp[1000];
        strcpy(temp, argv[1]);
        strcat(temp, filefo_path -> d_name);
        stat(temp, &attrib);
        struct tm* time_struct = gmtime(&attrib.st_ctime);

        if(time_struct -> tm_year + 1900 >= yer && time_struct -> tm_mday > day && time_struct -> tm_mon+1 >= mon){

            printf("%s %d %d %d\nPrevious Permissions : ", temp, time_struct -> tm_mday, time_struct -> tm_mon + 1, time_struct -> tm_year + 1900);
			printf((S_ISDIR(attrib.st_mode)) ? "d" : "-");
			printf((attrib.st_mode & S_IRUSR) ? "r" : "-");
			printf((attrib.st_mode & S_IWUSR) ? "w" : "-");
			printf((attrib.st_mode & S_IXUSR) ? "x" : "-");
			printf((attrib.st_mode & S_IRGRP) ? "r" : "-");
			printf((attrib.st_mode & S_IWGRP) ? "w" : "-");
			printf((attrib.st_mode & S_IXGRP) ? "x" : "-");
			printf((attrib.st_mode & S_IROTH) ? "r" : "-");
			printf((attrib.st_mode & S_IWOTH) ? "w" : "-");
			printf((attrib.st_mode & S_IXOTH) ? "x" : "-");
			printf("\n");
			printf("Changed Permissions : ");
			chmod(temp, mode);
        }
    }
	closedir(d);
	return 0;
}
