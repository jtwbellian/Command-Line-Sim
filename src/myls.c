#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


void detail(char *filename);

void myls(int size, char **argv) {
	struct dirent *dent;
	DIR *dp;

	if((dp = opendir("./")) == NULL) {
		exit(1);
	}

	if(size == 1) {
		while((dent = readdir(dp)) != NULL) {
			if(strcmp(dent->d_name, "..") == 0) {
				continue;
			} else if(strcmp(dent->d_name, ".") == 0) {
				continue;
			}

			printf("%s\t", dent->d_name);
		}
		printf("\n");

	} else if(size == 2) {
		if(strcmp(argv[1], "--help") == 0) {
			printf("myls command list directory comtents\n");
			printf("usage : myls [-l] [filename]\n");
			printf("[option] --help : print myls command usage\n\t-l : print detail contents of list directory contents\n");

			return;
			
		} else if(strcmp(argv[1], "-l") == 0) {
			while((dent = readdir(dp)) != NULL) {
				if(strcmp(dent->d_name, "..") == 0) {
					continue;
				} else if(strcmp(dent->d_name, ".") == 0) {
					continue;
				}

				detail(dent->d_name);
			}
			
		} else {
			int i;
			for(i = 0; i < size; i++) {
				printf("%s\n", argv[i]);
			}
			printf(": Invalid option\n");
		}

	} else if(size == 3) {
		if(strcmp(argv[1], "-l") == 0) {
			printf("50\n");
			detail(argv[2]);
			
		} else {
			int i;
			for(i = 0; i < size; i++) {
				printf("%s\n", argv[i]);
			}
			printf(": Invalid option\n");
		}
	}
}

void detail(char *filename) {
	struct stat statbuf;

	stat(filename, &statbuf);
	struct group *grp;
	struct passwd *pwd;
	grp = getgrgid((int)statbuf.st_gid);
	pwd = getpwuid((int)statbuf.st_uid);

	char permission[11];
	if(S_ISDIR(statbuf.st_mode)) {
		permission[0] = 'd';

	} else if(S_ISBLK(statbuf.st_mode)){
		permission[0] = 'b';

	} else if(S_ISCHR(statbuf.st_mode)) {
		permission[0] = 'c';

	} else if(S_ISFIFO(statbuf.st_mode)) {
		permission[0] = 'f';

	} else if(S_ISSOCK(statbuf.st_mode)) {
		permission[0] = 's';

	} else if(S_ISLNK(statbuf.st_mode)) {
		permission[0] = 'l';
		
	}else {
		permission[0] = '-';
	}

	if(statbuf.st_mode & S_IRUSR) {
		permission[1] = 'r';
	} else {
		permission[1] = '-';
	}

	if(statbuf.st_mode & S_IWUSR) {
		permission[2] = 'w';
	} else {
		permission[2] = '-';
	}

	if(statbuf.st_mode & S_IXUSR) {
		permission[3] = 'x';
	} else {
		permission[3] = '-';
	}

	if(statbuf.st_mode & S_IRGRP) {
		permission[4] = 'r';
	} else {
		permission[4] = '-';
	}
	
	if(statbuf.st_mode & S_IWGRP) {
		permission[5] = 'w';
	} else {
		permission[5] = '-';
	}

	if(statbuf.st_mode & S_IXGRP) {
		permission[6] = 'x';
	} else {
		permission[6] = '-';
	}

	if(statbuf.st_mode & S_IROTH) {
		permission[7] = 'r';
	} else {
		permission[7] = '-';
	}

	if(statbuf.st_mode & S_IWOTH) {
		permission[8] = 'w';
	} else {
		permission[8] = '-';
	}

	if(statbuf.st_mode & S_IXOTH) {
		permission[9] = 'x';
	} else {
		permission[9] = '-';
	}

	permission[10] = '\0';

	struct tm *tm;
	time_t t = statbuf.st_atime;
	tm = localtime(&t);
	char timebuf[80];
	strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M",tm);

	printf("%s %d %s %s %d %s %s\n", permission, (unsigned int)statbuf.st_nlink, pwd->pw_name, grp->gr_name, (int)statbuf.st_size, timebuf, filename);
}
