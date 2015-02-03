#include <stdio.h>

char
upper(char x)
{
    if (x >= 'a' && x <= 'z') {
        return x - 32;
    }
}

int
main()
{
    int id = 0;
    while (++id) {
        char x[51];
        scanf("%s\n", x);

        if (x[0] == '#') {
            break;
        }

        for (char pos = 0, *p = x;
             *p;
             *p = pos & 1 == 1 ? upper(*p) : *p, ++p, ++pos);

        printf("Case %d: %s\n", id, x);
    }
    return 0;
}

