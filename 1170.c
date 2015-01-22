#include <stdio.h>
#include <stdlib.h>

unsigned int l[100000000];

int
_cmp(const void* x1, const void* x2)
{
    return (*(unsigned int*) x1) - (*(unsigned int*) x2);
}

int
main()
{
    int idx = 0;
    while (1) {
        scanf("%d", &l[idx++]);

        if (l[idx - 1] == 0) {
            idx--;
            break;
        }
    }

    qsort(l, idx, sizeof(unsigned int), _cmp);

    printf("%d ", l[0]);
    for (int i = 1; i < idx; i++) {
        if (l[i] == l[i - 1]) {
        } else {
            printf("%d ", l[i]);
        }
    }

    return 0;
}
