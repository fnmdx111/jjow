#include <stdio.h>
#include <string.h>

char string_x[1001];
char string_y[1001];

void
do_()
{
    char string_z[1001];
    memset(string_z, 0, sizeof(string_z));

    for (int i = 0, len_x = strlen(string_x);
         i < len_x;
         ++i) {
        for (int j = 0, len_y = strlen(string_y);
             j < len_y;
             ++j) {
            if (string_x[i] == string_y[j]) {
                for (int k = 0; k < 1000; ++k) {
                    if (string_z[k] == string_x[i]) {
                        break;
                    } else if (!string_z[k]) {
                        string_z[k] = string_x[i];
                        break;
                    }
                }
            }
        }
    }

    for (int i = strlen(string_z); i > 0; --i) {
        printf("%c", string_z[i - 1]);
    }
    printf("\n");
}

int
main()
{
    while (1) {
        if (scanf("%s %s", string_x, string_y) == 2) {
            do_();
        } else {
            break;
        }
    }
    return 0;
}

