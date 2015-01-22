#include <stdio.h>
#include <string.h>


int arr[10000], brr[10000], crr[10000];

int
main()
{
    int x;
    int i = 0;
    scanf("%d", &x);

    while (x--) {
        int money = 0;
        int p, q;
        scanf("%d %d", &p, &q);

        memset(arr, 0, sizeof(arr));
        memset(brr, 0, sizeof(brr));
        memset(crr, 0, sizeof(crr));

        while (p--) {
            for (int j = 0; j < q; j++) {
                scanf("%d", &brr[j]);
                crr[j] = arr[j];
            }

            for (int j = 0; j < q; j++) {
                if (!j) {
                    arr[j] = brr[j] + crr[j];
                } else {
#define max(a, b) (a > b ? a : b)
                    arr[j] = max(arr[j - 1], max(crr[j - 1], crr[j]))
                           + brr[j];
                }
                money = max(arr[j], money);
            }
        }

        printf("Case #%d: %d\n", ++i, money);
    }

    return 0;
}
