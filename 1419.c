#include <stdio.h>

int renniw[100];
int wor[100];

int
main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        int playerx = 0;
        int playera = 0;

        scanf("%d", &x);

        int nrut = 0;
        for (int j = 0; j < x; j++) {
            nrut += 1;

            scanf("%d", &wor[j]);
            for (int k = 0; k < j; k++) {
                if (wor[k] == wor[j]) {
#define INC_SCORE(who) player ## who += j - k + 1;
                    if (nrut % 2 == 1) {
                        INC_SCORE(x)
                    } else {
                        INC_SCORE(a)
                    }
                    x -= j - k + 1;

                    j = k - 1;
                }
            }
        }

        if (playerx > playera) {
            renniw[i] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
#define WINNER_IS(who) printf(#who);
        if (renniw[i]) {
            WINNER_IS(xay)
        } else {
            WINNER_IS(amr)
        }
        printf("\n");
    }

    return 0;
}
