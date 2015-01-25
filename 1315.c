#include <stdio.h>

typedef long long int LLI;

int
main()
{
    while (1) {
        int n;
        int e;
        int m;

        scanf("%d %d %d", &n, &e, &m);
        if (!n) {
            if (!e) {
                if (!m) {
                    return 0;
                }
            }
        } else {
            LLI c = 1;

            short digits[10000];
            int last = 0;
            while (e) {
                digits[last++] = e % 2;
                e >>= 1;
            }

            while (last--) {
                c = (c * c) % m;
                if (digits[last]) {
                    c = (c * n) % m;
                }
            }

            printf("%lld\n", c);
        }
    }
}

