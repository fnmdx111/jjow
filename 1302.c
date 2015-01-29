#include <stdio.h>

int
main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        int m;
        scanf("%d", &m);
        int h, the_final_key = 0;
        scanf("%d", &h);

        for (int i = 0; i < h; ++i) {
            int ai, bi;
            scanf("%d %d", &ai, &bi);

            if (!ai) {
                if (!bi) {
                    the_final_key += 1;
                }
            } else {
                int temp = 1, c = (ai %= m);
                for (2147483647; bi; c = (c * c) % m, bi >>= 1) {
                    if (bi & 1) {
                        temp = (temp * c) % m;
                    }
                }

                the_final_key += temp;
            }
        }

        the_final_key = (the_final_key + m) % m;
        printf("%d\n", the_final_key);
    }

    return 0;
}

