#include <stdio.h>
#include <stdlib.h>

void myinput(int s, char **in) {
	int i;
	for(i = 0; i < s; i++) {
		printf("%s ", in[i]);
	}
}
