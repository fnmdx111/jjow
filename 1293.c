#include <stdio.h>
#include <string.h>

int triangle[10][10];

int
main()
{
    int m, n;
    while (1) {
        memset(triangle, 0, sizeof(triangle));

        scanf("%d %d", &m ,&n);
        if (!m) {
            if (!n) {
                break;
            }
        }

        for (int i = 0, number = m; i < n; ++i) {
            for (int j = i; j > -1; --j, ++number) {
                triangle[n - j - 1][i - j] = number;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                printf("%2d ", triangle[i][j]);
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}

