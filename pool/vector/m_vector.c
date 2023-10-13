#include "m_vector.h"
#include <stdio.h>

int main()
{
    int data[] = {1, 2, 3, 4};

    LineTable *LT = (LineTable *)malloc(sizeof(LineTable));

    Linear_Malloc(LT, 2);

    for (int i = 0; i < 4; i++)
        Line_Append(LT, &data[i]);

    printf("value: %d\n", *(int *)Line_Get(LT, 2));
    Line_Set(LT, 2, &data[3]);
    printf("value: %d\n", *(int *)Line_Get(LT, 2));

    Line_Free(LT);

    free(LT);

    return 0;
}
