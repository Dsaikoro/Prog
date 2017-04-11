#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	FILE *fp;
	double tate[256],yoko[256];
	int cnt,i;
	double tate_sum=0, yoko_sum=0;
	double tate_ave, tate_disp, yoko_ave, yoko_disp;

	//ファイルオープンチェック
	if ((fp = fopen("./donguris.csv","r")) == NULL){
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}

	for(cnt = 0; fscanf(fp,"%lf,%lf", &tate[cnt], &yoko[cnt]) != EOF; cnt++){
		tate_sum += tate[cnt];
		yoko_sum += yoko[cnt];
		printf("id:%d, tate:%.2f, yoko:%.2f\n",cnt, tate[cnt], yoko[cnt]);
	}
	fclose(fp);

	//平均値を求める
	tate_ave = tate_sum/cnt;
	yoko_ave = yoko_sum/cnt;

	//分散を求める
	tate_sum = 0;
	yoko_sum = 0;
	for (i = 0; i < cnt; i++){
		tate_sum += pow(tate[i] - tate_ave, 2);
		yoko_sum += pow(yoko[i] - yoko_ave, 2);		
	}
	tate_disp = tate_sum/cnt;
	yoko_disp = yoko_sum/cnt;

	printf("縦の平均値：%.3f\t分散：%.3f\t標準偏差：%.3f\n", tate_ave, tate_disp, sqrt(tate_disp));
	printf("横の平均値：%.3f\t分散：%.3f\t標準偏差：%.3f\n", yoko_ave, yoko_disp, sqrt(yoko_disp));

	return 0;
}