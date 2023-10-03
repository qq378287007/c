#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *arr, int low, int mid, int high)
{
    int *tmp = (int *)malloc(sizeof(int) * (high - low + 1));

    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;

    int k = 0;
    while(left_low <= left_high && right_low <= right_high)
    {
        if (arr[left_low] <= arr[right_low])
            tmp[k++] = arr[left_low++];
        else
            tmp[k++] = arr[right_low++];
    }

    for (int i = left_low; i <= left_high; i++)
        tmp[k++] = arr[i];
    // if (left_low <= left_high)
    //     memcpy(tmp + k, arr + left_low, sizeof(int) * (left_high - left_low + 1));

    for (int i = right_low; i <= right_high; i++)
        tmp[k++] = arr[i];
    // if (right_low <= right_high)
    //     memcpy(tmp + k, arr + right_low, sizeof(int) * (right_high - right_low + 1));

    for (int i = low; i <= high; i++)
        arr[i] = tmp[i - low];

    free(tmp);
}

void merge_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int a[] = {91, 54, 32, 87, 46};
    for (int i = 0; i < 5; i++)
        printf("%d\t", a[i]);
    printf("\n");

    merge_sort(a, 0, 4);

    for (int i = 0; i < 5; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return 0;
}