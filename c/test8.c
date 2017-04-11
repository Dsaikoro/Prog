#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	FILE *fp;
	char str[256] = {'\0'};
	int num[256] = {0};
	float sum = 0;
	float average, dispersion;
	int count = 0;
	int i;

	if ((fp = fopen("./hoge.txt","r")) == NULL){
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(str, 256, fp) != NULL){
		num[count] = atoi(str);
		printf("%d\n", num[count]);
		sum += num[count];
		if (++count > 256){
			printf("データが多すぎます。休ませてください。");
			return 0;
		}
	}
	fclose(fp);

	average = (float)sum/count;
	printf("平均値：%.3f\n", average);

	sum = 0;
	for (i = 0; i < count; i++){
		sum += pow(num[i] - average,2);
	}
	dispersion = sum/count;
	printf("分散：%.3f\n", dispersion);
	
	printf("標準偏差：%.3f\n", sqrt(dispersion));
		

	return 0;
}