#include <stdio.h>
#include <limits.h>

int list[10001];

int
main()
{
    int id = 0;
    while (++id) {
        int n;
        scanf("%d", &n);

        if (n < 0) {
            break;
        }

        int pos = INT_MAX;
#define min(a, b) ((a) < (b) ? (a) : (b))
        for (int i = 0; i < n; ++i) {
            scanf("%d", &list[i]);
            if (list[i] == 1) {
                pos = min(pos, i);
            }
        }

        int answer = 0;
        for (int i = pos + 1, x = 1; i < n; ++i) {
            if (list[i] == -1) {
                answer = x + answer;
            } else if (list[i] == 1) {
                x = 1 + x;
            }
        }

        printf("Case %d: %d\n", id, answer);
    }

    return 0;
}
