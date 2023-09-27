#include <stdio.h>

int partition(int *arr, int low, int high)
{
    int key = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= key)
            high--;
        if (low < high)
            arr[low++] = arr[high];

        while (low < high && arr[low] <= key)
            low++;
        if (low < high)
            arr[high--] = arr[low];
    }
    arr[low] = key;
    return low;
}

void quick_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pos = partition(arr, start, end);
        quick_sort(arr, start, pos - 1);
        quick_sort(arr, pos + 1, end);
    }
}

int main()
{
    int a[] = {91, 54, 32, 87, 46};
    for (int i = 0; i < 5; i++)
        printf("%d\t", a[i]);
    printf("\n");

    quick_sort(a, 0, 4);

    for (int i = 0; i < 5; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return 0;
}