#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 50
char* NewString(char* str);
int main(void) {
	char str[LEN];
	fgets(str,LEN, stdin);
	printf("%s", NewString(str));
	free(str);
	return 0;

}
char* NewString(char* str)
{
	int index = 0, flag1 = 0, flag2 = 0;
	char* tempStr = NULL;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			int digit = str[i] - '0';
			tempStr = (char*)realloc(tempStr, (sizeof(char) * (digit + index)));
			for (int j = 0;  j < digit;  j++)
			{
				tempStr[index++] = str[i];
			}
			flag1 = 0;
			flag2 = 0;
		}
		else if (str[i] == ' ' && flag1 == 0)
		{
			tempStr = (char*)realloc(tempStr, (sizeof(char) * (1 + index)));
			tempStr[index++] = '-';
			flag1 = 1;
			flag2 = 0;
		}
		else if (str[i] >= 'a' && str[i] <= 'z'&& flag2 ==0)
		{
			tempStr = (char*)realloc(tempStr, (sizeof(char) * (1 + index)));
			tempStr[index++] = '*';
			flag1 = 0;
			flag2 = 1;
		}
	}
	tempStr[index] = '\0';
	return tempStr;
}


