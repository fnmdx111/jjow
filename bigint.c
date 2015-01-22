#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 22

typedef struct _s
{
    unsigned int length;
    int _d[MAX_DIGITS];
} BigInteger;

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define ARY 100000000
#define D(var, idx) var->_d[idx]
#define TD(var) D(var, i)
#define ND(var) D(var, i + 1)
#define LEN(var) var->length
#define HD(var) D(var, LEN(var) - 1)
#define NHD(var) D(var, LEN(var))
#define INC_LEN(var) LEN(result) = min((LEN(result) + 1), MAX_DIGITS);

void
add_to(const BigInteger* x, const BigInteger* y, BigInteger* result)
{
    LEN(result) = max(LEN(x), LEN(y));

    for (int i = 0; i < LEN(result); ++i) {
        TD(result) = TD(x) + TD(y);
    }

    for (int i = 0; i < LEN(result); ++i) {
        if (TD(result) / ARY != 0) {
            if (ND(result) == 0) {
                INC_LEN(result)
            }
            ND(result) += TD(result) / ARY;
            TD(result) %= ARY;
        }
    }
}

void
init_big_integer(BigInteger* x, int v)
{
#define __init__(var, val)\
    BigInteger var;\
    memset(&var, 0, sizeof(BigInteger));\
    var.length = 1;\
    var._d[0] = val;

    __init__(a, v);
    __init__(b, 0);
#undef __init__

    memset(x, 0, sizeof(BigInteger));
    x->length = 1;

    add_to(&a, &b, x);
}

void
print_big_integer(const BigInteger* x)
{
    int i = LEN(x) - 1;
    printf("%d", TD(x));
    for (--i; i > -1; --i) {
        printf("%08d", TD(x));
    }
}

void
copy_big_integer(const BigInteger* from, BigInteger* to)
{
    memcpy(to, from, sizeof(BigInteger));
}

