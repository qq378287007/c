#include <stdio.h>

int main()
{
#define N 9
    int arr[N] = {1, 2, 3, 4};
    for (int i = 0; i < N; i++)
        printf("arr[%d]=%d\n", i, arr[i]);
    printf("\n");

    for (int i = 0; i < N; i++)
        printf("&arr[%d]=%d\n", i, &arr[i]);
    printf("\n");

    struct
    {
        char name[20];
        int score;
    } stu[N];
    for (int i = 0; i < N; i++)
        printf("&stu[%d]=%d\n", i, &stu[i]);
#undef N

#define M 5
#define N 3
    //int arr2[M][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[M][N] = {{1, 2, 3}, {4, 5}, {6}, {}};
    //int arr2[][N] = {{1, 2, 3}, {4, 5}, {6}, {}};

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            printf("arr2[%d][%d]=%d\t", i, j, arr2[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("%d, %d, %d\n", sizeof(arr2), sizeof(arr2[0]), sizeof(arr2[0][0]));

    return 0;
}