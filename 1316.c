#include <stdio.h>

char digits[1000000];

int
main()
{
    while (1) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (!x) {
            if (!y) {
                return 0;
            } else {
                printf("0\n");
            }
        } else {
            int last = 0;
            char z = 0;
            while (x) {
#define PUSH(x) digits[last++] = x;
                if (x % y == 0) {
                    PUSH('0')
                    x /= y;
                } else {
                    if (x < 0) {
                        z = x % y - y;
                        x /= y;
                        x++;
                    } else {
                        z = x % y;
                        x /= y;
                    }

                    z += (z > 9) ? 'A' - 10 : '0';
                    PUSH(z)
                }
            }

            while (last--) {
                printf("%c", digits[last]);
            }
            printf("\n");
        }
    }

    return 0;
}

