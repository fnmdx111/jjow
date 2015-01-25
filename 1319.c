#include <stdio.h>
#include <string.h>

char digits[40000];

int
main()
{
    int _;
    scanf("%d", &_);

    while (_--) {
        int x;
        scanf("%d", &x);

        memset(digits, 0, sizeof(digits));
        int last = 0;

        if (!x) {
            printf("%d\n", 0);
            continue;
        }

        while (x) {
            switch (x % 3) {
#define PUSH(x) digits[last++] = x;
                case 2:
                    x = x / 3 + 1;
                    PUSH('-')
                    break;
                case -2:
                    x = x / 3 - 1;
                    PUSH('1')
                    break;
                case -1:
                    x = x / 3;
                    PUSH('-')
                    break;
                default:
                    PUSH(48 + x % 3)
                    x /= 3;
            }
        }

        while (digits[--last] == '0');

        for (int i = last; i >= 0; --i) {
            printf("%c", digits[i]);
        }

        printf("\n");
    }

    return 0;
}

