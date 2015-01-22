#include <stdio.h>

int
main()
{
    int super_long_variable_name_that_you_cannot_imagine;
    scanf("%d", &super_long_variable_name_that_you_cannot_imagine);

    for (int i = 0; i < super_long_variable_name_that_you_cannot_imagine; i++) {
        long int x_1;
        long int x_2;
        long int x_3;

        scanf("%ld %ld %ld", &x_1, &x_2, &x_3);
        printf("%.2lf\n", x_2 / (1. * x_1) * x_3);
    }

    return 0;
}
