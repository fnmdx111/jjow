#include <stdio.h>

#define LLI long long int

LLI
a_function(LLI x, LLI y)
{
    return (x + y) * (y - x + 1) / 2;
}

int
main()
{
    int x;
    int i = 0;
    scanf("%d", &x);

    while (x--) {
        LLI var1, var2;
        scanf("%lld %lld", &var1, &var2);
        printf("Case #%d: %lld\n", ++i, a_function(var1, var2));
    }

    return 0;
}
