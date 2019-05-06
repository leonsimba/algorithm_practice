#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX	128

char stack[STACK_MAX];
const int n = STACK_MAX;
int top = 0;

int push(char c)
{
	if (top >= n) {
		return -1;
	}
	stack[top++] = c;
	return 0;
}

int pop(char *c)
{
	if (top > 0) {
		*c = stack[--top];
		return 0;
	}

	return -1;
}

int isValid(char *expr)
{
	int len = strlen(expr);
	int i, ret;

	for (i = 0; i < len; i++) {
		char last;

		switch (expr[i]) {
			case '{':
			case '[':
			case '(':
				push(expr[i]); break;
			case '}':
			case ']':
			case ')':
				ret = pop(&last);
				if (ret < 0)
					return -1;	// not valid
				if ((expr[i] == '}' && last != '{') ||
					(expr[i] == ']' && last != '[') ||
					(expr[i] == ')' && last != '('))
					return -1;	// not valid
				break;
			default:
				break;
		};
	}

	if (top == 0)
		return 0;
}

int main()
{
	char *expr1 = "{[{}]}";
	char *expr2 = "[{()}]";
	char *expr3 = "{[}()]";
	char *expr4 = "[({)}]";

	int ret;

	top = 0;
	ret = isValid(expr1);
	if (ret < 0)
		printf("%s Not valid\n", expr1);

	top = 0;
	ret = isValid(expr2);
	if (ret < 0)
		printf("%s Not valid\n", expr2);

	top = 0;
	ret = isValid(expr3);
	if (ret < 0)
		printf("%s Not valid\n", expr3);

	top = 0;
	ret = isValid(expr4);
	if (ret < 0)
		printf("%s Not valid\n", expr4);

	return 0;
}
