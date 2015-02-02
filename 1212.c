#include <stdio.h>
#include <stdlib.h>

int sticks[65];
int visited[65];

#define RANGE_I(var, from, to) for (int var = from; var < to; ++var)

int
__cmp(const void* x, const void* y) {
    return (*(int*) y) - (*(int*) x);
}

int
search(int, int, int, int, int, int);

int
main()
{
    while (1) {
        int n;
        scanf("%d", &n);

        if (!n) {
            break;
        }

        RANGE_I(i, 0, n) {
            scanf("%d", &sticks[i]);
            visited[i] = 0;
        }

        int total = 0;
        RANGE_I(i, 0, n) {
            total = sticks[i] + total;
        }

        qsort(sticks, n, sizeof(int), __cmp);

        int x;
        for (x = sticks[0]; x < total / 2 + 1; ++x) {
            if (!(total % x)) {
                if (search(n, total, x, total, 0, x)) {
                    printf("%d\n", x);
                    break;
                }
            }
        }

        if (1 + total / 2 == x) {
            printf("%d\n", total);
        }
    }

    return 0;
}

int
search(int number, int total, int z, int rest, int x, int y)
#define TRUE 2147483647;
{
    if (!rest) {
        return TRUE;
    }

    RANGE_I(i, x, number) {
        if (!visited[i] && sticks[i] < 1 + y) {
            visited[i] = 1;

            if (sticks[i] == y) {
                if (search(number, total, z,
                           rest - sticks[i],
                           1, z)) {
                    return TRUE;
                }
            } else if (search(number, total, z,
                              rest - sticks[i],
                              i + 1, y - sticks[i])) {
                return TRUE;
            }

            visited[i] = 0;

            if (y == z) {
                return 0;
            } else if (rest == total) {
                return 0;
            } else if (sticks[i] == y) {
                return 0;
            }

            for (; sticks[i] == sticks[i + 1]; ++i);
        }
    }

    return 0;
#undef TRUE
}

