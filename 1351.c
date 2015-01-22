#include <stdio.h>

int
do_()
{
    int month, day;
    scanf("%d %d", &month, &day);

    int total = 0;
#define INC(v) total += v;
#define MINOR INC(30)
#define MAJOR INC(31)
    for (int i = month; i < 8; ++i) {
        if (i == 1) {
            MAJOR
        } else if (i == 2) {
            INC(29)
        } else if (i == 3) {
            MAJOR
        } else if (i == 4) {
            MINOR
        } else if (i == 5) {
            MAJOR
        } else if (i == 6) {
            MINOR
        } else if (i == 7) {
            MAJOR
        } else if (i == 8) {
            MAJOR
        }
    }

    return total - day + 8;
}

int
main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        printf("%d\n", do_());
    }
}
