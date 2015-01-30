#include <stdio.h>
#include <stdlib.h>

typedef struct Girl
{
    int beauty;
    int smartness;
} Girl;

Girl gs[100001];

int
cmp(const void* x, const void* y)
{
    return ((Girl*) x)->beauty - ((Girl*) y)->beauty;
}

int
main()
{
    while (1) {
        int n;
        scanf("%d", &n);

        if (!n) {
            break;
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d", &gs[i].beauty);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &gs[i].smartness);
        }

        qsort(gs, n, sizeof(Girl), cmp);

        int answer = 0;
        for (int i = 0, smin = 2147483647; i < n; ++i) {
            answer += gs[i].smartness < smin ? 1 : 0;
#define min(a, b) (a < b ? a : b)
            smin = min(smin, gs[i].smartness);
        }

        printf("%d\n", answer);
    }

    return 0;
}

