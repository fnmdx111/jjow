#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[10001];
char str2[10001];
int temp[10001];

int
cmp(const void* x1, const void* x2)
{
    return (*(int*) x1) - (*(int*) x2);
}

int
main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        scanf("%s", str1);
        scanf("%s", str2);

        int x;
        scanf("%d", &x);

        int length = strlen(str1);

        for (int i = 0; i < length; ++i) {
            temp[i] = abs(str1[i] - str2[i]);
        }

        qsort(temp, length, sizeof(int), cmp);

        for (int i = 0; i < x; ++i) {
            if (temp[length - i - 1]) {
                temp[length - i - 1] = 0;
            } else {
                temp[length - i - 1] = 1;
            }
        }

        int count = 0;
        while (length--) {
            count += temp[length];
        }

        printf("%d\n", count);
    }

    return 0;
}

