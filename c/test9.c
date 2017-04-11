#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char str[256] = {'\0'};
	int num[256] = {0};
	int count = 0;
	int i,j,tmp;

	if ((fp = fopen("./hoge.txt","r")) == NULL){
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(str, 256, fp) != NULL){
		num[count] = atoi(str);
		//printf("%d\n", num[count]);
		if (++count > 256){
			printf("データが多すぎます。休ませてください。");
			return 0;
		}
	}
	fclose(fp);
	
	for (i = 0; i < count; i++){
		for(j = count-1; j > 0 + i; j--){
			if(num[j] < num[j-1]){
				tmp = num[j];
				num[j] = num[j-1];
				num[j-1] = tmp;
			}
		}
		printf("%d\n", num[i]);
	}

	return 0;
}