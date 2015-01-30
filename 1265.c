#include <stdio.h>
#include <string.h>

typedef unsigned char BYTE;

BYTE visited[6000000];

int
main()
{
    while (1) {
        int k;
        scanf("%d", &k);

        if (k < 0) {
            break;
        }

        memset(visited, 0, sizeof(visited));

        int x = 0;
        for (int i = 1, last = 0; k--; last = x, visited[x] = 1, ++i) {
            int temp = last - i;

            if (temp > 0 && !visited[temp]) {
                x = temp;
            } else {
                x = last + i;
            }
        }

        printf("%d\n", x);
    }

    return 0;
}

