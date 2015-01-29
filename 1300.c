#include <stdio.h>

int
main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        int the_figure;
        scanf("%d", &the_figure);

        if ((the_figure % 7) > 1) {
            printf("%s\n", "Sproblvem");
        } else {
            printf("%s\n", "Dzs");
        }
    }

    return 0;
}
