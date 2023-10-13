#pragma once

#include <stdlib.h>
#include <assert.h>

typedef struct
{
    void **_store;
    int _size;
    int _cap;
} LineTable;

#define Linear_Malloc(LT, SZ)                             \
    {                                                     \
        LT->_cap = SZ;                                    \
        LT->_size = 0;                                    \
        LT->_store = (void **)calloc(SZ, sizeof(void *)); \
    }

#define Line_Append(LT, V)           \
    {                                \
        if (LT->_size >= LT->_cap)   \
            Line_Extend(LT);             \
        LT->_store[LT->_size++] = V; \
    }

#define Line_Extend(LT)                                                        \
    {                                                                      \
        int _cap = LT->_cap * 3;                                           \
        LT->_store = (void **)realloc(LT->_store, sizeof(void **) * _cap); \
        assert(LT->_store != NULL);                                        \
        LT->_cap = _cap;                                                   \
    }

#define Line_Free(LT)     \
    {                     \
        free(LT->_store); \
    }

#define Line_Get(LT, I) (LT->_store[I])

#define Line_Set(LT, I, V) (LT->_store[I] = V)
