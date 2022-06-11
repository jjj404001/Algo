#ifndef _UTIL_H
#define _UTIL_H

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


typedef struct String
{
    char* data;
    int length;
} String;

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


#endif