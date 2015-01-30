#include <stdio.h>

#define D400_YEARS (365 * 400 + 100 - 3)
#define D100_YEARS (365 * 100 + 25)
#define DNL100_YEARS (D100_YEARS - 1)
#define D4_YEARS (365 * 4 + 1)
#define DNL4_YEARS (D4_YEARS - 1)
#define D1_YEARS 366
#define DNL1_YEARS 365

#define __N(y) D ## y ## _YEARS
#define __NNL(y) DNL ## y ## _YEARS
#define REMOVE_G(some_years)\
    year += some_years * (n / __N(some_years));\
    n %= __N(some_years);
#define REMOVE_G_NL(some_years)\
    year += some_years * (n / __NNL(some_years));\
    n %= __NNL(some_years);
#define REMOVE(some_years)\
    year += some_years;\
    n -= __N(some_years);
#define REMOVE_NL(some_years)\
    year += some_years;\
    n -= __NNL(some_years);
#define SET_LEAP_MONTH month_days[2] = 29;

int
main()
{
    while (1) {
        int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int n;
        scanf("%d", &n);

        if (n < 0) {
            break;
        }
        char* weekdays[7] = {"Saturday", "Sunday", "Monday",
                             "Tuesday", "Wednesday", "Thursday",
                          "Friday"};
        char* weekday = weekdays[n % 7];

        int year = 0;

        REMOVE_G(400)

        if (n >= D100_YEARS) {
            REMOVE(100)
            REMOVE_G_NL(100)

            if (n >= DNL4_YEARS) {
                REMOVE_NL(4)
                REMOVE_G(4)

                if (n < D1_YEARS) {
                    SET_LEAP_MONTH
                } else {
                    REMOVE(1)
                    REMOVE_G_NL(1)
                }
            } else {
                REMOVE_G_NL(1)
            }
        } else {
            if (n >= D4_YEARS) {
                REMOVE_G(4)
            }

            if (n < D1_YEARS) {
                SET_LEAP_MONTH
            } else {
                REMOVE(1)
                REMOVE_G_NL(1)
            }
        }

        int month = 1;
        for (n += 1; month < 13; ++month) {
            if (month_days[month] >= n) {
                break;
            } else {
                n = n - month_days[month];
            }
        }

        printf("%d-%02d-%02d %s\n", year + 2000, month, n, weekday);
    }

    return 0;
}
