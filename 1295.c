#include <stdio.h>
#include <string.h>

char stack[1002];
int last = 0;
#define PUSH(v) stack[++last] = v
#define sPUSH(v) PUSH(v);
#define POP stack[last--]
#define sPOP POP;
#define EMPTY (last == 0)
#define TOP stack[last]

int
main()
{
    int n, i = 0;
    scanf("%d", &n);
    getchar();

    while (n--) {
        i++;
        memset(stack, 0, sizeof(stack));
        last = 0;

        char x, y;
        while ((x = getchar()) != '\n') {
            switch (x) {
                case '{':
                case '[':
                case '(':
                    sPUSH(x)
                    y = '?';
                    break;
                case '}':
                    y = '{';
                    break;
                case ']':
                    y = '[';
                    break;
                case ')':
                    y = '(';
                    break;
                default:
                    y = '!';
            }

            if (y == '!') {
            } else if (y == '?') {
                continue;
            } else {
                if (TOP == y) {
                    sPOP
                } else {
                    sPUSH('@')
                }
            }
        }

        printf("Case %d: ", i);
        if (EMPTY) {
            printf("Legal\n");
        } else {
            printf("Illegal\n");
        }
    }

    return 0;
}

