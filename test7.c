#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char str[256] = {'\0'};

	if ((fp = fopen("./hoge.txt","r")) == NULL){
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(str, 256, fp) != NULL){
		printf("%d\n", atoi(str));
	}
	
	fclose(fp);

	return 0;
}