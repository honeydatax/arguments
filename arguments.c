#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	char memo[80];
	char memo2[2080];
	int n;
	printf("\ec\e[44;36m\a\n");
	if(argc>1)printf("%s",argv[1]);
	printf("\nget argument list to program?");
	fgets(memo,78,stdin);
	memo2[0]=0;
	if(argc>1){
		strcpy(memo2,argv[1]);
		strcat(memo2," ");
	}
	strcat(memo2,memo);
	system(memo2);
	return 0;
}
