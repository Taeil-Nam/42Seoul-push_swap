#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
	int count = atoi(argv[1]);

	if (argc != 2)
		return 1;

	srand(time(NULL));
	for (int i = 0; i < count; i++)
		printf("%d ", ((rand() & 0xFF) << 24) + ((rand() & 0xFF) << 16) + ((rand() & 0xFF) << 8) + (rand() & 0xFF));
	printf("\n");

	RAND_MAX;
	return 0;
}
