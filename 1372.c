#include <stdio.h>
#include <stdlib.h>

#define UINT unsigned int

int
_cmp(const void* x1, const void* x2)
{
    return (*(UINT*) x1) - (*(UINT*) x2);
}

UINT array[100001];

int
main()
{
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < n; ++i) {
            int tmp;
            scanf("%d", &tmp);
            array[i] = tmp;
        }

        qsort(array, n, sizeof(UINT), _cmp);

        for (int i = 0; i < n; i += m) {
            printf("%d%c", array[i], i < n - m ? ' ': '\n');
        }
    }

    return 0;
}

