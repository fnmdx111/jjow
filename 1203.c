#include <stdio.h>

int
most_appeared_number(int n)
{
    int count = 0, reg = 0;
    while (n--) {
        int x;
        scanf("%d", &x);

        if (count > 0) {
            if (x == reg) {
                count = 1 + count;
            } else {
                count = -1 + count;
            }
        } else {
            reg = x;
            count = 1;
        }
    }

    return reg;
}

int
main()
{
    while (1) {
        int n;
        if (scanf("%d", &n) != 1) {
            break;
        }

        printf("%d\n", most_appeared_number(n));
    }

    return 0;
}

