#include <stdio.h>
#include <string.h>

int grid[1000001][4];

int
c(int i, int a, int b, int c, int d)
{
    return grid[i][0] * a + grid[i][1] * b +\
           grid[i][2] * c + grid[i][3] * d;
}

int
main()
{
    while (1) {
        int n;
        if (scanf("%d", &n) != 1) {
            break;
        }

        memset(grid, 0, sizeof(int) * n);

        grid[1][3] = grid[2][0] = grid[2][1] = grid[2][2] = 1;
        grid[2][3] = 2;

        for (int i = 3; i <= n; ++i) {
            grid[i][0] = c(i - 1, 0, 0, 0, 1);
            grid[i][1] = c(i - 1, 1, 0, 1, 0) % 10000;
            grid[i][2] = c(i - 1, 1, 1, 0, 0) % 10000;
            grid[i][3] = c(i - 1, 1, 1, 1, 1) % 10000;
        }

        printf("%d\n", grid[n][3]);
    }

    return 0;
}

