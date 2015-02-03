#include <stdio.h>

int
main()
{
    while (1) {
        int m, p, n;
        scanf("%d %d %d", &m, &p, &n);

        if (m == 0 && p == 0 && n == 0) {
            break;
        }

        int answer = 0;
        if (n * p >= m) {
            answer = n * p;
        } else {
            answer = m;
        }

        printf("%d\n", answer);
    }

    return 0;
}
