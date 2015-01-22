#include <stdio.h>

int
main()
{
    int n;
    scanf("%d", &n);

    int total = 0;
    for (int i = 0; i < 2 * n + 1; i++) {
        int x;
        scanf("%d", &x);
        total ^= x;
    }

    printf("%d\n", total);

    return 0;
}
