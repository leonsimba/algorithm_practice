

int match(char *pattern, char *target)
{
	int i = 0, j = 0;
	int len1 = strlen(pattern);
	int len2 =  strlen(target);

	for (i = 0; i < len1; i++) {
		if (pattern[i] == '*') {
				last = j;
				j = len2;

				if (i == len)
			}

		} else {
			if (pattern[i] == target[j]) {
				i++;
				j++;
				continue;
			} else {
				return -1;	// not match
			}
		}

	}

	return 0; // match
}
