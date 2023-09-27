#include <stdio.h>

void bubble_sort(int *arr, int n)
{
    double tmp;
    for (int i = 1; i <= n - 1; i++)
    {
        int flag = 1;
        for (int j = n - 1; j >= i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                tmp = arr[j], arr[j] = arr[j - 1], arr[j - 1] = tmp;
                flag = 0;
            }
        }
        if (flag)
            break;
    }
}

int main()
{
    int a[]={91,54,32,87,46};
    for(int i=0; i<5; i++)
        printf("%d\t", a[i]);
    printf("\n");
    
    bubble_sort(a, 5);

    for(int i=0; i<5; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return 0;
}