#include <stdio.h>
#include <stdlib.h>

int numbers[10001];
int temp[10001];

int
merge(int* a, int* b, int low, int mid, int high)
{
    int k = low;
    int head1 = low;
    int tail1 = mid;
    int head2 = mid + 1;
    int tail2 = high;

    int ret = 0;
    while (k <= high) {
        if (head1 > tail1) {
            b[k++] = a[head2++];
        } else if (head2 > tail2) {
            b[k++] = a[head1++];
        } else {
            if (a[head1] <= a[head2]) {
                b[k++] = a[head1++];
            } else {
                b[k++] = a[head2++];
                ret += abs(head2 - k);
            }
        }
    }

    return ret;
}

int
merge_sort(int* a, int* b, int from, int to)
{
    if (from >= to) {
        return 0;
    }

    int middle = (from + to) / 2;

    int x = merge_sort(a, b, from, middle);
    int y = merge_sort(a, b, middle + 1, to);
    int z = merge(a, b, from, middle, to);

    return x + y + z;
}

int
main()
{
    while (1) {
        int n;
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
            temp[i] = 0;
        }

        printf("%d\n", merge_sort(numbers, temp, 0, n - 1));
    }

    return 0;
}

