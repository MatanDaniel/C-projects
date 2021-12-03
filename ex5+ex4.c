#define _CRT_SECURE_NO_WARNINGS //question 5//
#include <stdio.h>
#define LENGTH 80
void Decipher(char text[]);
void calculator(char String1[]);
float CharToInt(char c);

void main()
{
	char str1[LENGTH], str2[LENGTH];
	printf("Enter input for the string:\n");
	gets(str1);
	
	printf("Enter input for the string:\n");
	gets(str2);

	calculator(str1);
	Decipher(str2);
}

void calculator(char String1[])
{
	char sign;
	int index = 0, i = 10, flag = 0, length1 = 0, length2 = 0, op = 0, op1 = 1, counter;
	double answer = 0;
	float n1 = 0, n2 = 0;
	while (String1[op] != '+' && (String1[op] != '*') && String1[op] != '-' && String1[op] != '/')
	{
		op++;
	}
	while (String1[index] != ' ')
	{
		if (String1[index] == '.')
		{
			flag = 1;
			index++;
		}
		if (!flag)
		{
			n1 = n1 * 10 + CharToInt(String1[index]);
		}
		else
		{
			n1 = n1 + (CharToInt(String1[index]) / i);
			i *= 10;
			length1++;
		}
		index++;
	}
	sign = String1[op];
	index += 3;
	flag = 0;
	i = 10;
	while (String1[index] != '\0')
	{
		if (String1[index] == '.')
		{
			flag = 1;
			index++;
		}
		if (!flag)
		{
			n2 = n2 * 10 + CharToInt(String1[index]);
		}
		else
		{
			n2 = n2 + CharToInt(String1[index]) / i;
			i *= 10;
			length2++;
		}
		index++;
	}
	switch (sign)
	{
	case '+': answer = n1 + n2; break;
	case '*': answer = n1 * n2; break;
	case '-': answer = n1 - n2; break;
	case '/': answer = n1 / n2; break;
	default:
		break;
	}
	int firstDot = 0, secondDot = 0;
	for (i = 0; String1[i] != '\0'; i++) {
		if (String1[i] == '.') {
			if (op1 == 1)
				firstDot = i;
			else
				secondDot = i;
		}
		else if (String1[i] == '+' || String1[i] == '-' || String1[i] == '*' || String1[i] == '/')
			op1 = 0;
	}
	for (int j = 0; String1[j] != '\0'; j++)
	{
		counter = j;
	}
	int accleft = 0, accright = 0;
	if (firstDot != 0)
		accleft = op - 2 - firstDot;
	if (secondDot != 0)
		accright = counter - 1 - secondDot;
	if (length1 == 0 && length2 == 0)
	{
		printf("%ld\n", (long)answer);
	}
	if (accleft > 0 && accright == 0 || accright > 0 && accleft == 0)
	{

		printf("%ld.", (long)answer);
		for (int i = 0; i < accleft || i < accright; i++, answer *= 10)
		{
			int k = (int)((answer - (long)answer) * 10);
			printf("%d", k);
		}
		printf("\n");
	}
	if (length1 > 0 && length2 > 0)
	{
		int j = (long)answer;
		printf("%ld.", (long)answer);
		for (int i = 0; i < accleft && i < accright; i++, answer *= 10)
		{
			int k = (int)((answer - (long)answer) * 10);
			printf("%d", k);

		}
		printf("\n");
	}
}
float CharToInt(char c)
{
	int number = c - '0';
	return number;

}
void Decipher(char text[LENGTH])
{
	int counter = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == ' ')
		{
			counter = 0;
			printf(" ");
		}
		else
		{
			counter++;
			printf("%c", text[i] - counter);
		}
	}
		printf("\n");
}
