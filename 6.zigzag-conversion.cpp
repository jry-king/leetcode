#include <iostream>
#include <string> 
#include <fstream>
using namespace std;

/*
 * First deal with edge situations.
 * Then generate the result one line by another.
 * Same as approach 2.
 * O[n] time complexity and O[n] space complexity
 * 12 ms, faster than 99.49%
 * 10.1 MB, less than 100%
 */
class Solution {
public:
    string convert(string s, int numRows) 
    {
        string ans = "";
        int len = s.length();
        int group = 2 * numRows - 2;        // see this many letters as one group, help divide lines below
        
        // some special situations
        if (numRows == 1 || len <= numRows)
        {
            return s;
        }
        
        // generate result one row by another
        for (int i = 0; i < numRows; i++)
        {
            // first/last line, just one letter per group
            if (i == 0 || i == (numRows-1))
            {
                for (int j = i; j < len; j += group)
                {
                    ans += s[j];
                }
            }
            // the other lines have two letters per group, add both if exist
            else
            {
                for (int j = i; j < len; j += group)
                {
                    ans += s[j];
                    int k = j + group - 2 * i;
                    if (k < len)
                    {
                        ans += s[k];
                    }
                }
            }
        }
        return ans;
    }
};