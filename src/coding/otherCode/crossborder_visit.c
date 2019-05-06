#include <stdio.h>

int main(int argc, char *argv[])
{
	long int i = 1;
	int arr[3] = {0};

	// array cross-border visit
	for (; i <= 3; i++) {
		arr[i] = 2;	
		printf("hello world\n");
	}

	return 0;
}
