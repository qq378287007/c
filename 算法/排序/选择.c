#include <stdio.h>

void select_sort(int *arr, int n)
{
    double tmp;
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        if (k != i)
        {
            tmp = arr[i], arr[i] = arr[k], arr[k] = tmp;
        }
    }
}

int main()
{
    int a[] = {91, 54, 32, 87, 46};
    for (int i = 0; i < 5; i++)
        printf("%d\t", a[i]);
    printf("\n");

    select_sort(a, 5);

    for (int i = 0; i < 5; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return 0;
}