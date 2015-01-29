#include <stdio.h>

int
main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        int mmmmm;
        scanf("%d", &mmmmm);

        int x = 0, y = 0, z = 0;
        for (int i = 0, a = 1, b = 0, c = 0;
             i < mmmmm * 2;
             i++, a = x, b = y, c = z) {
            x = 2 * (b + c);
            y = a;
            z = b + c;
        }

        printf("%d\n", x + y + z);
    }

    return 0;
}

