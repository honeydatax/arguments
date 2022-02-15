#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	int n;
	printf("\ec\e[44;36m\a\n");
	for(n=0;n<argc;n++)printf("%s\n",argv[n]);
	sleep(15);
	return 0;
}
