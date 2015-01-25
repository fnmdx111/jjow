#include <stdio.h>

int
main()
{
    char x;
    while (1) {
        x = getchar();

        if ('2' <= x && x <= '9') {
            printf("%c", x - 1);
        }
#define DEFT(ch, ech)\
        else if (x == ch) {\
            printf(#ech);\
        }
#define DEFS(ch, s_ech)\
        else if (x == ch) {\
            printf(s_ech);\
        }
        DEFS('1', "`")
        DEFS('0', "-")
        DEFS('-', "0")
        DEFT('W', Q)
        DEFT('E', W)
        DEFT('R', E)
        DEFT('T', R)
        DEFT('Y', T)
        DEFT('U', Y)
        DEFT('I', U)
        DEFT('O', I)
        DEFT('P', O)
        DEFT('[', P)
        DEFT('S', A)
        DEFT('D', S)
        DEFT('F', D)
        DEFT('G', F)
        DEFT('H', G)
        DEFT('J', H)
        DEFT('K', J)
        DEFT('L', K)
        DEFT(';', L)
        DEFS('\'', ";")
        DEFS(' ', " ")
        DEFT('X', Z)
        DEFT('C', X)
        DEFT('V', C)
        DEFT('B', V)
        DEFT('N', B)
        DEFT('M', N)
        DEFT(',', M)
        DEFS('.', ",")
        DEFS('/', ".")
        else if (x == '\n') {
            break;
        }
    }

    return 0;
}

