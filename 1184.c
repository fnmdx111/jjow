#include <stdio.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

int
square_root(int squared)
{
    double guess = 1;

    while (abs((guess * guess) / squared - 1.0) >= 0.00001) {
        guess = (squared / guess + guess) / 2;
    }

    return (int) guess;
}

int
main()
{
    while (1) {
        int n;
        if (scanf("%d", &n) != 1) {
            break;
        }

        printf("%d\n", square_root(n));
    }

    return 0;
}

