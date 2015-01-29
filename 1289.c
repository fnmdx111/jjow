#include <stdio.h>
#include <string.h>

int
string_length(char* str)
{
    int l;
    for (l = 0; *str; ++l, str++);

    return l;
}

int
is_complementary(char d1, char d2)
{
#define DEF(ch1, ch2)\
    if (d1 == ch1) {\
        if (d2 == ch2) {\
            return 2147483647;\
        } else {\
            return 0;\
        }\
    }

    DEF('A', 'T')
    else DEF('C', 'G')
    else DEF('G', 'C')
    else DEF('T', 'A')

#undef DEF
}

char str1[101];
char str2[101];

int
main()
{
    while (1) {
        memset(str1, 0, sizeof(str1));
        scanf("%s", str1);

        if ('#' == *str1) {
            break;
        }

        memset(str2, 0, sizeof(str2));
        scanf("%s", str2);

        int length = string_length(str1);
        int answer = 0;
        for (int i = 0;
             i < length;
             answer += is_complementary(str1[i], str2[i]) ? 0 : 1, ++i);

        printf("%d\n", answer);
    }
}

