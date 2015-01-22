#include <stdio.h>

int
main()
{
    int integer;

    while (1) {
        scanf("%d", &integer);

        switch (integer) {
#define PRSLN(s) printf(#s "\n");
            case 0:
                return 0;
            case 1:
                PRSLN(1)
                break;
            case 2:
                PRSLN(2);
                break;
            case 4:
                PRSLN(2 2);
                break;
            default: {
                switch (integer % 3) {
#define PRSP printf(" ");
#define PRN(n) printf(#n);
#define PRLN printf("\n");
#define PRPR \
                    PRSP \
                } else { \
                    PRLN
                    case 2:
                        PRN(2) PRSP
                        for (int i = 0; i < integer / 3; i++) {
                            PRN(3)
                            if (i != integer / 3 - 1) {
                                PRPR
                            }
                        }
                        break;
                    case 1:
                        PRN(2 2) PRSP
                        for (int i = 0; i < integer / 3 - 1; i++) {
                            PRN(3)
                            if (i != integer / 3 - 2) {
                                PRPR
                            }
                        }
                        break;
                    case 0:
                        for (int i = 0; i < integer / 3; i++) {
                            PRN(3)
                            if (i != integer / 3 - 1) {
                                PRPR
                            }
                        }
                }
            }
        }
    }

    return 0;
}

