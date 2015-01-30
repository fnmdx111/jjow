#include <stdio.h>
#include <string.h>

int
main()
{
    int f;
    scanf("%d", &f);

    int k;
    scanf("%d", &k);

    int array[10001];
    memset(array, 0, sizeof(array));
    int count = 0;

    while (k--) {
        int l, i;
        scanf("%d %d", &l, &i);

        for (int ll = l - 1; ll < f; ll += i) {
            if (!array[ll]) {
                array[ll] = 1;
                count += 1;
            }
        }
    }

    printf("%d\n", f - count);

    return 0;
}

