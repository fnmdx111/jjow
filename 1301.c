#include <stdio.h>
#include <string.h>

int array[100001];

int
main()
{
    int _;
    scanf("%d", &_);

    while (_--) {
        memset(array, 0, sizeof(array));

        int n, s;
        scanf("%d %d", &n, &s);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &array[i]);
        }

        int temp = 0, length = 0, minimum = 2147483647;
        for (int i = 0; i < n; ++i) {
            temp += array[i];
            length += 1;

            for (; s < temp;
                 temp -= array[i - length + 1], length -= 1) {
#define min(a, b) (a < b ? a : b)
                minimum = min(minimum, length);
            }
        }

        if (!(minimum ^ 2147483647)) {
            minimum = 0;
        }

        printf("%d\n", minimum);
    }

    return 0;
}

