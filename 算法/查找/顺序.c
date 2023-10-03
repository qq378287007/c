#include <stdio.h>

int order_search(int *arr, int n, int des)
{
    for (int i = 0; i < n; i++)
    {
        if (des == arr[i])
            return i;
    }
    return -1;
}

int main()
{
    int a[] = {91, 54, 32, 87, 46};

    printf("index: %d\n", order_search(a, 5, 32));

    return 0;
}
