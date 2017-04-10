#include<stdio.h>
#include<math.h>
#include <string.h>

float getNum(char *str);
int main(void)
{
	char str[] = "20.412\t16";
	char *s1,*s2;
	float num1,num2;

	s1 = strtok(str, "\t");
	s2 = strtok(NULL, "\t");
	num1 = getNum(s1);
	num2 = getNum(s2);
	printf("s1:%f\n", num1);
	printf("s2:%f\n", num2);
	printf("str:%s\n", str);
}

float getNum(char *str)
{
	int cnt;
	int point;
	float num = 0;
	
	for (cnt = 0; (str[cnt] >= '0') && (str[cnt] <= '9'); cnt++){			//整数部分を取得
		num = 10*num + (str[cnt] - '0');
	}
	if (str[cnt] == '.'){
		point = cnt;								//小数点も場所を保存
		for(cnt = 1; (str[point+cnt] >= '0') && (str[cnt+point] <= '9'); cnt++){	//少数部分を取得
			num = num + pow(10,-1*cnt)*(str[cnt+point]-'0');
			printf("%f\n", num);
			printf("%f\n", pow(10,-1*cnt));
		}
	}

	return num;
}
