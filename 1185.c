#include <stdio.h>
#include <limits.h>

int grid[101][101];
int search(int, int);

int
main()
{
    while (1) {
        int m, n;
        if (scanf("%d %d", &m, &n) != 2) {
            break;
        }

        for (int i = 0; i < m + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                grid[i][j] = INT_MIN;
            }
        }

        for (int i = 0; i < m + 1; ++i) {
            grid[i][1] = 1;
        }

        for (int j = 0; j < n + 1; ++j) {
            grid[0][j] = 1;
        }

        int ret = search(m, n);
        printf("%d\n", ret);
    }

    return 0;
}

int
search(int m, int n)
{
    if (m >= 0) {
        if (grid[m][n] == INT_MIN) {
            grid[m][n] = search(m - n, n) + search(m, n - 1);
        }

        return grid[m][n];
    } else {
        return 0;
    }
}

