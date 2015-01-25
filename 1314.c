#include <stdio.h>

int get_length_of_longest_chain(int number, int count);

int
main()
{
    while (1) {
        int i, j;
        scanf("%d %d", &i, &j);

        if (!i && !j) {
            return 0;
        }

        int max_length = -2147483648;
        for (int k = i; k <= j; ++k) {
#define max(a, b) (a > b ? a : b)
            max_length = max(max_length, get_length_of_longest_chain(k, 1));
        }
        printf("%d\n", max_length);
    }

    return 0;
}

int
get_length_of_longest_chain(int number, int count)
{
    if (number == 1) {
        return count;
    } else if (number % 2) {
        return get_length_of_longest_chain(3 * number + 1, count + 1);
    } else {
        return get_length_of_longest_chain(number / 2, count + 1);
    }
}

