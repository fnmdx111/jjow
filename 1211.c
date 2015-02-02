#include <stdio.h>
#include <string.h>

char _str[100];
char str[100];

char stack[100];
int calc[100];
#define ptr(s) s[0]
#define INIT_STACK(s) ptr(s) = 0;
#define PUSH(s, v) s[++ptr(s)] = v;
#define POP(s) s[ptr(s)--];
#define EMPTY(s) (ptr(s) == 0)
#define TOP(s) s[ptr(s)]

char precedence[128];

int
precede(char op1, char op2)
{
    return precedence[op1] - precedence[op2] >= 0 ? 1 : 0;
}

int
is_numeric(char x)
{
    if (x <= '9' && x >= '0') {
        return 1;
    }

    return 0;
}

void
get_integer()
{
    int x = 0, multiplier = 1;
    while (!EMPTY(stack) && is_numeric(TOP(stack))) {
        x += (TOP(stack) - '0') * multiplier;
        multiplier *= 10;

        POP(stack)
    }

    PUSH(calc, x)
}

void
calculate()
{
    char op = TOP(stack);
    POP(stack)

    if (op == '@') {
        return;
    }

    int x = TOP(calc);
    POP(calc)

    int y = TOP(calc);
    POP(calc)

    int z = 0;
    switch (op) {
        case '+':
            z = x + y;
            break;
        case '-':
            z = y - x;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            z = y / x;
            break;
        default:
            break;
    }

    PUSH(calc, z)
}

int
main()
{
    precedence['('] = 0;
    precedence[')'] = 1;
    precedence['+'] = precedence['-'] = 2;
    precedence['*'] = precedence['/'] = 3;
    precedence['@'] = -1;

    int n;
    scanf("%d\n", &n);

    while (n--) {
        char* _p_str = _str;
        while ((*_p_str = getchar()) != '\n') {
            _p_str++;
        }
        *_p_str = '\0';

        sprintf(str, "%s@", _str);

        INIT_STACK(stack)
        INIT_STACK(calc)

        for (size_t i = 0, length = strlen(str); i < length; ++i) {
            if (str[i] == ' ') {
            } else {
                if (is_numeric(str[i])) {
                    PUSH(stack, str[i])
                } else {
                    if (!EMPTY(stack)) {
                        if (is_numeric(TOP(stack))) {
                            get_integer();
                        }
                    }

                    if (str[i] == '(') {
                        PUSH(stack, '(')
                    } else if (str[i] == ')') {
                        while (TOP(stack) != '(' && !EMPTY(stack)) {
                            calculate();
                        }
                        POP(stack)
                    } else {
                        while (!EMPTY(stack) && precede(TOP(stack), str[i])) {
                            calculate();
                        }
                        PUSH(stack, str[i])
                    }
                }
            }
        }

        printf("%d\n", TOP(calc));
    }

    return 0;
}

