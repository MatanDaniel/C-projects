#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Multiply(int a, int b) {
    int sum = a * b;
    return sum;
}
int Plus(int a, int b) {
    int sum = a + b;
    return sum;
}
int Minus(int a, int b) {
    int sum = a - b;
    return sum;
}
int Divide(int a, int b) {
    int sum;
    if (b != 0) {
        sum = a / b;
    }
    else {
        printf("Math Error\n");
    }
    return sum;

}
int Next(int a) {
    int b;
    int sum = a;
    int whichFunc;
    printf("for Minus: 1,for Plus : 2, for Multiply : 3, for Divide : 4, for Finish : 5\n");
    scanf("%d", &whichFunc);
    scanf("%d", &b);

    if (whichFunc != 5) {
        if (whichFunc == 1) {
            sum = Minus(a, b);
        }
        else if (whichFunc == 2) {
            sum = Plus(a, b);

        }
        else if (whichFunc == 3) {
            sum = Multiply(a, b);

        }
        else if (whichFunc == 4) {
            // להכניס תנאי חילוק ב0 כאן********************
            sum = Divide(a, b);
        }

    }
    else {
        return 0;
    }

    printf("The result is: %d\n", sum);
    Next(sum);
}




int main(void) {
    int whichFunc;
    int sum;
    int a;
    int b;
    printf("for Minus: 1,for Plus : 2 , for Divide : 4 , for Multiply : 3\n");
    scanf("%d", &whichFunc);
    printf("Enter two values:\n");
    scanf("%d%d", &a, &b);
    if (whichFunc == 1) {
        sum = Minus(a, b);

    }
    else if (whichFunc == 2) {
        sum = Plus(a, b);

    }
    else if (whichFunc == 3) {
        sum = Multiply(a, b);

    }
    else if (whichFunc == 4) {
        sum = Divide(a, b);

    }
    printf("The result is: %d\n", sum);
    Next(sum);
    printf("The result is: %d\n", sum);
}

