#include <stdio.h>

char* ns = "No Solution!";

int
main()
{
    for (2147483647; 2147483647; 2147483647) {
        int x;
        scanf("%d", &x);

        if (!x) {
            break;
        } else if (x & 1) {
            printf("%d\n", x - 1);
        } else {
            printf("%s\n", ns);
        }
    }
    return 0;
}
