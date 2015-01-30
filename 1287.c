#include <stdio.h>
#include <string.h>

typedef long long int LLI;

int
main()
{
    while (1) {
        int n;
        if (scanf("%d", &n) != 1) {
            break;
        }

        LLI x[51];
        memset(x, 0, sizeof(x));

        x[0] = x[1] = 1;
        for (int i = 2; i < 26; ++i) {
            for (int j = i - 1; j > -1; --j) {
                LLI temp = x[i - j - 1] * x[j];
                x[i] = temp + x[i];
            }
        }

        printf("%lld\n", n ? x[n / 2] : 0);
    }

    return 0;
}
