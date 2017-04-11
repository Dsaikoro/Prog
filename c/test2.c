#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	srand((unsigned)time(NULL));
	
	for (i = 0; i < 100; i++)
		printf("%d:%d\n", i+1, rand()%100 + 1);

	return 0;
}