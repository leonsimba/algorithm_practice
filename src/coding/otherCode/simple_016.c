#include <stdio.h>

#define INVALID		0x1000

int check_valid(char * bytes, int len)
{
	int i = 0;

	while (i < len) {
		char b = bytes[i];
		int j, count = 0;
		unsigned char flag = 1;

		if ((b & (1 << 7)) == 0) {	// the first bit of b is 0
			i++;
			continue;
		}

		// count the number of 1
		while (flag) {
			if (b & flag) {
				count++;
			} else {
				if (count)
					return 1; 	// invaild, such as 1111 0001
			}
			flag = flag << 1;
		}
		// printf("bytes[%c] = %x, count =  %d\n", i, bytes[i], count);
		i++;

		if (i + count > len)	// invalid
			return 1;

		for (j = 0; j < count; j++) {
				// check if it start as '01'
				if ( (bytes[i + j] & (1 << 6)) == (1 << 6)) {
					continue;
				} else {
					return 1; 	// invaild
				}
		}
		i = i + count;
	}

	return 0;
}


void main()
{
	int invalid;
	char bytes_1[] = {(char)0x01, (char)0x60, (char)0x71, (char)0x72};
	char bytes_2[] = {(char)0x01, (char)0xa0, (char)0x71, (char)0x72};
	char bytes_3[] = {(char)0x01, (char)0xe0, (char)0x71, (char)0x72};
	char bytes_4[] = {(char)0x01, (char)0xe0, (char)0x71, (char)0x72, (char)0x73};
	char bytes_5[] = {(char)0x01, (char)0xe0, (char)0x71, (char)0x02, (char)0x73};

	invalid = check_valid(bytes_1, sizeof(bytes_1));
	printf("invaild = %d\n", invalid);

	invalid = check_valid(bytes_2, sizeof(bytes_2));
	printf("invaild = %d\n", invalid);

	invalid = check_valid(bytes_3, sizeof(bytes_3));
	printf("invaild = %d\n", invalid);

	invalid = check_valid(bytes_4, sizeof(bytes_4));
	printf("invaild = %d\n", invalid);

	invalid = check_valid(bytes_5, sizeof(bytes_5));
	printf("invaild = %d\n", invalid);

	return;
}
