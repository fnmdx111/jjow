#include <stdio.h>

int image[41][41];

void
do_(int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &image[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (image[i][j]) {

                int counter = 0;
                for (int k = image[i][j]; k != 1; k >>= 1) {
                    if (k & 1) {
                        counter += 1;
                    }
                }

                if (counter & 1 == 1) {
                    image[i][j] = 0;
                } else {
                    image[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            printf("%d ", image[i][j]);
        }
        printf("%d\n", image[i][n - 1]);
    }
}

int
main()
{
    while (1) {
        int n;
        if (scanf("%d", &n) != 1) {
            break;
        }

        do_(n);
    }
    return 0;
}
