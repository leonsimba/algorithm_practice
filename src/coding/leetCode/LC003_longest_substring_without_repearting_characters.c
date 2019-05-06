
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX		26

void length_of_longest_substring(char *str, int len)
{
	int left, cur_len;
	int last_left, last_len;
	int hash[MAX];
	int i;

	memset(hash, 0, sizeof(hash));
	left = last_left = 0;
	last_len = cur_len = 0;

	for (i = 0; i < len; i++) {
		int pos;
		int index = str[i] - 'a';

		// we meet a duplicate character
		if (pos = hash[index]) {
			int j;

			// clear the hash table for the character which we need removed
			for (j = left; j < pos; j++) {
				hash[str[j] - 'a'] = 0;
			}
			left = pos;				// move on left side
			cur_len = i - pos + 1;	// update current len
			hash[index] = i + 1;
			printf("Del, %c, cur_len = %d, left = %d, last_len = %d, last_left = %d, hash[%c] = %d\n", str[i], cur_len, left, last_len, last_left, str[i], hash[index]);
		} else {		// the character has not in range [left, high]
			cur_len++;
			hash[index] = i + 1; // pos start from 1
			if (cur_len > last_len) {
				last_len = cur_len;
				last_left = left;
			}

			printf("Add, %c, cur_len = %d, left = %d, last_len = %d, last_left = %d, hash[%c] = %d\n", str[i], cur_len, left, last_len, last_left, str[i], hash[index]);
		}
	}

	printf("%s, longest substring len = %d, start = %d, \n", str, last_len, last_left);
	for (i = last_left; i < (last_left + last_len); i++)
		printf("%c", str[i]);
	printf("\n");
}

// sloution 2:
#if 0
void length_of_longest_substring(char *str, int len)
{
	int hash[MAX];
	int *lsub
}

int f[100];
int func(char *str, int len) {
	int i, max;
	int hash[26] = {0};
	max = f[0] = 1;
	hash[str[0]-'a'] = 1;
	for(i=1;i<len;i++)
	{
		if(hash[str[i]-'a']) {
			f[i] = f[hash[str[i]-'a']];
			hash[str[i]-'a'] = i;
		}
		else {
			f[i] = f[i-1] + 1;
			hash[str[i]-'a'] = i;
		}

		if(max < f[i]) max=f[i];
	}
	return max;
}
#endif

void test_01()
{
	char str1[]="abcabcbb";
	char str2[]="bbbbb";
	char str3[]="pwwkew";
	char str4[]="abceebc";
	char str5[]="abcadefdacba";
	char str6[]="abcaaabcdef";

	length_of_longest_substring(str1, sizeof(str1) - 1);
	length_of_longest_substring(str2, sizeof(str2) - 1);
	length_of_longest_substring(str3, sizeof(str3) - 1);
	length_of_longest_substring(str4, sizeof(str4) - 1);
	length_of_longest_substring(str5, sizeof(str5) - 1);
	length_of_longest_substring(str6, sizeof(str6) - 1);
}

void main()
{
	test_01();
}
