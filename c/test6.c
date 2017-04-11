#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	FILE *fp;
	int i;
	char num[256] = {'\0'};
	srand((unsigned)time(NULL));
	
	if ((fp = fopen("./hoge.txt","w")) == NULL){
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 100; i++){
		sprintf(num, "%d\n", rand()%100+1);
		fputs(num, fp);
	}

	fclose(fp);
	
	return 0;
}