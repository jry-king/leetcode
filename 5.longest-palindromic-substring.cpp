#include <iostream>
#include <string>
using namespace std;

/*
 * first trial, similar as solution 4
 * pick letter one by one as centers and expand, checking whether letters at both sides are the same
 * and detect string composed of identical letters to avoid redundant check
 * O[n**2] time complexity and O[1] space complexity
 * 8 ms, faster than 92.53%
 * 10 MB, less than 51.72%
 */

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int low = 0;
        for (int high = 0; high < s.length(); high++)
        {
            if (high + 1 < s.length() && s[low] == s[high + 1])
            {
                continue;
            }
            int temp = 0;
            while (low - temp >= 0 && high + temp < s.length() && s[low - temp] == s[high + temp])
            {
                if (res.length() < (high - low + 1 + 2 * temp))
                {
                    res = s.substr(low - temp, high - low + 1 + 2 * temp);
                }
                temp++;
            }
            low = high + 1;
        }
        return res;
    }
};