#include <stdio.h>

typedef unsigned long long UDL;

UDL
calc(UDL p, UDL q)
{
    return (p - 1) * (q - 1) - 1;
}

int
main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        UDL x;
        scanf("%llu", &x);
        UDL y;
        scanf("%llu", &y);

        UDL result = calc(x, y);
        printf("%llu\n", result);
    }

    return 0;
}
