#ifndef _UTIL_H
#define _UTIL_H

extern "C"
{

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))



void print2d(int** dp, int h, int w)
{
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            printf("%d, ", dp[i][j]);
        }
        printf("\n");
    }
}

void alloc2d(void** arr, size_t size, int w, int h)
{
    arr = (void**)malloc(sizeof(int*) * h);
    for(int i = 0; i <= h; i++)
        arr[i] = (void*)malloc(size * w);
}

void free2d(void** arr, size_t size, int h)
{
    for(int i = 0; i <= h; i++)
        free((void*)arr[i]);
    free((void*)arr);
}

}

#endif