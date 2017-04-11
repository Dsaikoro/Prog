#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct donguri{
	int id;
	float tate;
	float yoko;
	char type;
};

int main(void)
{
	FILE *fp;
	char label[256], str[256];
	int cnt, i, num1, num2;
	struct donguri data[256];
	struct donguri tmp;

	//データ読み取り
	if ((fp = fopen("./donguri3.csv", "r")) == NULL){
		printf("donguri3.csv open error\n");
		exit(EXIT_FAILURE);
	}
	fgets(label, 256, fp);	//一行目はラベルなので読み飛ばす
	for (cnt = 0; fscanf(fp, "%d,%f,%f,%c", &data[cnt].id, &data[cnt].tate, &data[cnt].yoko, &data[cnt].type) != EOF; cnt++);  	//データの読み取り
	fclose(fp);
	
	//データシャッフル
	srand((unsigned)time(NULL));
	for (i = 0; i < 1000; i++){
		num1 = rand()%cnt;
		num2 = rand()%cnt;
		tmp = data[num1];
		data[num1] = data[num2];
		data[num2] = tmp;
	}

	//データ出力
	if ((fp = fopen("./donguri4.csv", "w")) == NULL){
		printf("donguri4.csv open error\n");
		exit(EXIT_FAILURE);
	}
	fputs(label, fp);
	for(i = 0; i < cnt; i++){
		sprintf(str, "%d,%.1f,%.1f,%c\n", data[i].id, data[i].tate, data[i].yoko, data[i].type);
		fputs(str, fp);
	}
	fclose(fp);

	return 0;	
}
