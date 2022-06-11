/* Implementation of both Longest Common Subsequence and 
 * Longest Common Substring
 *
 * Longest Common subsequence : "ABCDE", "ACEDB"
 *  result is A,C,D. for Subsequence, it doesnt needs to be successive.
 *
 * Longest Common Substring   : "ABCDE", "ACDEB"
 *  result is C,D.
 * */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include "Util.h"

#ifdef DP
/*Dynamic programming*/
void LongestCommonSubsequence(String* s1, String* s2, String* result)
{
    int** dp = NULL; // hard coded for now.
    
    dp = (int**)malloc(sizeof(int*) * (s1->length +1));
    for(int i = 0; i <= s1->length; i++)
        dp[i] = (int*)malloc(sizeof(int) * (s2->length + 1));

    for(int i =0; i <= s1->length; i++)
        memset(dp[i],0, s2->length * sizeof(int));

    for(int i = 1; i <= s1->length; i++)
        for(int j = 1; j <= s2->length; j++)
        {
            if(s1->data[i-1] == s2->data[j-1])
                dp[i][j] = dp[i-1][j-1] +1;
            else
                dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
        }
    result->length = dp[s1->length][s2->length];
    print2d((int**)dp, s1->length +1, s2->length +1);

    result->data = (char*)malloc(sizeof(char) * result->length +1);

    int str_i = result->length-1;
    int stk_j = s2->length;

    for(int i = s1->length; i > 0; --i)
    {
        for(int j = stk_j; j > 0; --j)
        {
            if(dp[i][j] > dp[i-1][j-1] && dp[i-1][j] < dp[i][j] && dp[i][j-1] < dp[i][j])
            {
                result->data[str_i--] = s1->data[i-1];
                stk_j = j-1;
                break;
            }
        }
    }
    result->data[result->length] = '\0';


    for(int i = 0; i <= s1->length; i++)
        free((void*)dp[i]);
    free((void*)dp);
}
void LongestCommonSubstring(String* s1, String* s2, String* result)
{
    int** dp = NULL;
    
    dp = (int**)malloc(sizeof(int*) * (s1->length +1));
    for(int i = 0; i <= s1->length; i++)
        dp[i] = (int*)malloc(sizeof(int) * (s2->length + 1));

    for(int i =0; i <= s1->length; i++)
        memset(dp[i],0, s2->length * sizeof(int));

    for(int i = 1; i <= s1->length; i++)
        for(int j = 1; j <= s2->length; j++)
        {
            if(s1->data[i-1] == s2->data[j-1])
                dp[i][j] = dp[i-1][j-1] +1;
        }
    result->length = dp[s1->length][s2->length];
    print2d((int**)dp, s1->length +1, s2->length +1);

    result->data = (char*)malloc(sizeof(char) * result->length +1);

    int str_i = 0;
    int max = 0;

    for(int i = s1->length; i > 0; --i)
    {
        for(int j = s2->length; j > 0; --j)
        {
            if(dp[i][j] > max)
            {
                max = dp[i][j];
                int k = i, w = j;
                while(dp[k][w] == dp[k-1][w-1]+1)
                {
                    result->data[str_i++] = s1->data[k-1];
                    --k;--w;
                }
            }
        }
    }
    String new_result = {(char*)malloc(sizeof(char) * (max +1)), max +1};
    for(int i = 0; i < max; i++) // strcpy
        new_result.data[i] = result->data[i];
    new_result.data[max] = '\0';

    free(result->data);
    result->data = new_result.data;
    result->length = new_result.length;


    for(int i = 0; i <= s1->length; i++)
        free((void*)dp[i]);
    free((void*)dp);
}
#endif
#ifdef RE
/*Recursion*/
void LongestCommonSubsequence(String* s1, String* s2, String* result)
{

}
#endif

int main(int argc, char* argv[])
{
    String substring = {};
    String subsequence = {};

    // Ignore Null terminator
    String a = {"ABCDAD", 6};
    String b = {"ACBAD", 5};

    printf("String 1 =%s\n", a.data);
    printf("String 2 =%s\n", b.data);
    //LongestCommonSubsequence(&a, &b, &subsequence);
    LongestCommonSubstring(&a, &b, &substring);

    printf("length = %d\n", subsequence.length);
    printf("subsequence is = %s\n", subsequence.data);

    free((void*)subsequence.data);

    return 0;
}
