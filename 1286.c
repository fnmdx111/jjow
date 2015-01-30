#include <stdio.h>
#include <math.h>

#define SQR(x) ((x) * (x))

double
cosine_formula_rad(double x, double y, double z)
{
    return (SQR(x) + SQR(y) - SQR(z)) / (2 * x * y);
}

double
cosine_formula_deg(double x, double y, double z)
{
    return acos(cosine_formula_rad(x, y, z));
}

void
swap(double* a, double* b)
{
    double c;
    c = *a;
    *a = *b;
    *b = c;
}

int
main()
{
    while (1) {
        int x[3], y[3], z[3];

        if (scanf("%d %d %d %d %d %d %d %d %d",
                  &x[0], &y[0], &z[0],
                  &x[1], &y[1], &z[1],
                  &x[2], &y[2], &z[2]) != 9) {
            break;
        }

        double length[3];
        for (int i = 0, k = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j, ++k) {
                length[k] = SQR(x[i] - x[j]) +\
                            SQR(y[i] - y[j]) +\
                            SQR(z[i] - z[j]);
                length[k] = sqrt(length[k]);
            }
        }

        double* p = length[2] < length[0] ? &(length[0]) : &(length[2]);
        p = length[2] < length[1] ? &(length[1]) : p;
        swap(p, &(length[2]));

        double ang_rad = cosine_formula_rad(length[0], length[1], length[2]);
        double denominator = length[2] / (sqrt(1 - SQR(ang_rad)) * 2);

        double half_deg = cosine_formula_deg(length[0], length[1], length[2]) / 2;
        double numerator = tan(half_deg) * (length[0] + length[1] - length[2]) / 2;

        printf("%.3lf\n", SQR(numerator) / SQR(denominator));
    }

    return 0;
}

