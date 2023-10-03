#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int binary_search(int *arr, int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midValue = arr[mid];
        if (midValue < key)
            low = mid + 1;
        else if (midValue > key)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int a[] = {32, 46, 54, 87, 91};

    printf("index: %d\n", binary_search(a, 5, 46));

    return 0;
}
