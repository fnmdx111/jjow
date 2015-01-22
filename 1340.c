#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
#define STRING(v) char v[201]; memset(v, 0, sizeof(v));
        STRING(family)
        STRING(given)

        scanf("%s %s", family, given);
#define DO(which)\
        for (char* c = which; *c != '\0'; ++c) {\
            *c = tolower(*c);\
        }\
        which[0] = toupper(which[0]);

        DO(family)
        DO(given)

        printf("%s %s\n", given, family);
    }

    return 0;
}

