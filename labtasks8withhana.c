//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>

//Author: Matan Daniel, ID: 315783522 
//*/
//int LetterCount(char str[]) // question number 1 // 
//{
//	int counter = 0;
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		counter++;
//	}
//	return counter;
//}
//int main(void) {
//	char str[80];
//	printf("Enter letters in order to get the sum:\n");
//	gets(str);
//	printf("The number of characters your have in %s: is: %d\n", str, LetterCount(str));
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define N 80
//int LetterCount(char str[]) // question number 1 // 
//{
//	int counter = 0;
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		counter++;
//	}
//	return counter;
//}
//
//void ReverseString(char str[])
//{
//	int length= LetterCount(str);
//	char newString[N];
//	for (int i = 0; str[i] != '\0'; i++) {
//		newString[i] = length-1-i;
//	}
//	newString[length] = '\0';
//	printf("the reverse string is:%s", newString);
//
//      
//}
//int main(void){
//	char str[N];
//	gets(str);
//	ReverseString(str);
//	return 0;
//}

//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define N 80
//int LetterCount(char str[]) // question number 1 // 
//{
//	int counter = 0;
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		counter++;
//	}
//	return counter;
//}
//void ReversePrint(char str[])
//{
//	int length = LetterCount(str);
//	for (int i = length-1; i>=0; i--)
//	{
//		printf("%c", str[i]);
//	}
//}
//int main(void) {
//	char str[N];
//	printf("Enter a string:\n");
//	gets(str);
//	ReversePrint(str);
//	return 0;
//}

int Matrix(int index)
{
    int matan[SIZE][SIZE];


    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("pleae enter #%d of the row and #%d of the collum:\n", i + 1, j + 1);
            scanf("%d", &matan[i][j]);
        }

    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            printf(" %d|", matan[i][j]);
        }

        printf("\n");
    }

    int counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (index == matan[i][j])
                counter++;
        }

    }

    printf("the num %d is in the array #%d times", index, counter);

    return counter;

}