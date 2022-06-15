/* Implementation of both Longest Common Subsequence and 
 * Longest Common Substring
 *
 * Longest Common subsequence : "ABCDE", "ACEDB"
 *  result is A,C,D. for Subsequence, it doesnt needs to be successive.
 *
 * Longest Common Substring   : "ABCDE", "ACDEB"
 *  result is C,D.
 * */
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

#include "Util.hpp"

#ifdef DP
/*Dynamic programming*/
void LongestCommonSubsequence(std::string s1, std::string s2, std::string& result)
{
    int** dp = NULL; // hard coded for now.
    
    dp = (int**)malloc(sizeof(int*) * (s1.length() +1));
    for(int i = 0; i <= s1.length(); i++)
        dp[i] = (int*)malloc(sizeof(int) * (s2.length() + 1));

    for(int i =0; i <= s1.length(); i++)
        memset(dp[i],0, s2.length() * sizeof(int));

    for(int i = 1; i <= s1.length(); i++)
        for(int j = 1; j <= s2.length(); j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] +1;
            else
                dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
        }
    print2d((int**)dp, s1.length() +1, s2.length() +1);
    result.reserve(dp[s1.length()][s2.length()]);

    int str_i = dp[s1.length()][s2.length()]-1;
    int stk_j = s2.length();

    for(int i = s1.length(); i > 0; --i)
    {
        for(int j = stk_j; j > 0; --j)
        {
            if(dp[i][j] > dp[i-1][j-1] && dp[i-1][j] < dp[i][j] && dp[i][j-1] < dp[i][j])
            {
                result.push_back(s1[i-1]);
                stk_j = j-1;
                break;
            }
        }
    }
    std::reverse(std::begin(result), std::end(result));

    for(int i = 0; i <= s1.length(); i++)
        free((void*)dp[i]);
    free((void*)dp);
}
void LongestCommonSubstring(std::string s1, std::string s2, std::string& result)
{
    int** dp = NULL;
    
    dp = (int**)malloc(sizeof(int*) * (s1.length() +1));
    for(int i = 0; i <= s1.length(); i++)
        dp[i] = (int*)malloc(sizeof(int) * (s2.length() + 1));

    for(int i =0; i <= s1.length(); i++)
        memset(dp[i],0, s2.length() * sizeof(int));

    for(int i = 1; i <= s1.length(); i++)
        for(int j = 1; j <= s2.length(); j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] +1;
        }
    print2d((int**)dp, s1.length() +1, s2.length() +1);
    result.reserve(dp[s1.length()][s2.length()]);

    int str_i = 0;
    int max = 0;

    for(int i = s1.length(); i > 0; --i)
    {
        for(int j = s2.length(); j > 0; --j)
        {
            if(dp[i][j] > max)
            {
                max = dp[i][j];
                int k = i, w = j;
                while(dp[k][w] == dp[k-1][w-1]+1)
                {
                    result.push_back(s1[k-1]);
                    --k;--w;
                }
            }
        }
    }
    std::reverse(std::begin(result), std::end(result));


    for(int i = 0; i <= s1.length(); i++)
        free((void*)dp[i]);
    free((void*)dp);
}
#endif
#ifdef RE
/*Recursion*/
void LongestCommonSubsequenceAUX(int** dp, int i, int j)
{

}

void LongestCommonSubsequence(std::string s1, std::string s2, std::string& result)
{

}
#endif

int main(int argc, char* argv[])
{
    std::string substring = "";
    std::string subsequence = "";

    // Ignore Null terminator
    std::string a = "ABCDAD";
    std::string b = "ACBAD";

    std::cout << "String 1=" << a << std::endl;
    std::cout << "String 2=" << b << std::endl;
    LongestCommonSubsequence(a, b, subsequence);
    LongestCommonSubstring(a, b, substring);

    std::cout << "length = " << subsequence.length() << std::endl;
    std::cout << "subsequence is = " << subsequence << std::endl;

    return 0;
}
