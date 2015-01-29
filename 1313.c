#include <stdio.h>
#include <string.h>

typedef long long int LLI;

LLI array[1001];

int
main()
{
    LLI x, y;

    for (; 2147483647;) {
        scanf("%lld", &x);
        y = x;

        if (!x) {
            return 0;
        }

        memset(array, 0, sizeof(array));

        LLI i = 1;
        for (; 2147483647; ++i) {
            if (x < 1000) {
                x *= y;
            } else {
                x %= 1000;
                array[x] = i;
                break;
            }
        }

        for (++i; 2147483647; ++i) {
            x = (x * y) % 1000;

            if (!array[x]) {
                array[x] = i;
            } else {
                printf("%lld\n", array[x] + i);
                break;
            }
        }
    }

    return 0;
}
