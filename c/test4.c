#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i,j;
	int num[100] = {0};
	int tmp;

	srand((unsigned)time(NULL));
	
	printf("びふぉー\n");
	for (i = 0; i < 100; i++){
		num[i] = rand()%100 + 1;
		printf("%d:%d\n", i+1, num[i]);
	}
	
	printf("あふたぁー\n");
	for (i = 0; i < 100; i++){
		for (j = 99; j > 0+i; j--){
			if (num[j] < num[j-1]){
				tmp = num[j];
				num[j] = num[j-1];
				num[j-1] = tmp;
			}
		}
		printf("%d:%d\n", i, num[i]); 
	}
	
	
	return 0;
}