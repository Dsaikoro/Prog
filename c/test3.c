#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	int num = 0;
	float sum = 0;
	srand((unsigned)time(NULL));
	
	for (i = 0; i < 100; i++){
		num = rand()%100 + 1;
		printf("%d:%d\n", i+1, num);
		sum += num;
	}
	printf("sum = %d\n", (int)sum);
	printf("average = %.2f\n", sum/100);

	return 0;
}