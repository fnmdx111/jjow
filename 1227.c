#include <stdio.h>
#include <string.h>

int grid[11][11];
int max_val = 0;

#define max(a, b) (a > b ? a : b)

void
search(int g[11][11], int n, int coord_a, int coord_b, int total)
{
    if (!coord_a && coord_b + 1 == n) {
        max_val = max(max_val, total + g[coord_a][coord_b]);
        return;
    }

    if (coord_b < n - 1) {
        search(g, n, coord_a, coord_b + 1, total + g[coord_a][coord_b]);
    }

    if (coord_a > 0) {
        search(g, n, coord_a - 1, coord_b, total + g[coord_a][coord_b]);
    }
}

int
main()
{
    int weight[128];
    memset(weight, 0, sizeof(weight));

    for (int i = 0; i < 10; ++i) {
        weight[i + '0'] = i;
    }
    weight['A'] = 1;
    weight['J'] = 11;
    weight['Q'] = 12;
    weight['K'] = 13;
    weight['T'] = 10;

    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char x, suit, space;
            scanf("%c%c%c", &x, &suit, &space);

            grid[i][j] = weight[x];
        }
    }

    search(grid, n, n - 1, 0, 0);
    printf("%d\n", max_val);

    return 0;
}

