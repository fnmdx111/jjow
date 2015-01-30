
array = [0 for _ in range(102)]
array[0] = array[1] = 1

for i in range(2, 101):
    for j in range(0, i):
        array[i] += array[i - j - 1] * array[j]

table = '{%s}' % ', '.join('"%d"' % x for x in array)

c_src = '''#include <stdio.h>

char* table[101] = %s;

int
main()
{
    while (1) {
        int n;
        scanf("%%d", &n);

        if (n < 0) {
            break;
        }

        printf("%%s\\n", table[n]);
    }
    return 0;
}
''' % table

with open('1268.table.c', 'w') as f:
    f.write(c_src)

