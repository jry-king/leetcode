#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * optimized sliding window, add character to substring one by one,
 * and if duplicate character appears, truncate the former part of the substring divided by this character, then add this character to the end
 * O[n] time complexity and O[max(m,n)] space complexity
 * m, n is the size of the string and the alphabet
 * 20 ms faster than 64.85%
 * 23.1 MB, less than 10.95%
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        string substring = "";
        for (int i = 0; i < s.length(); i++)
        {
            string::size_type n = substring.find(s[i]);
            if (string::npos != n)
            {
                length = max(length, int(substring.length()));
                substring = substring.substr(n + 1);
                substring += s[i];
            }
            else
            {
                substring += s[i];
            }
        }
        length = max(length, int(substring.length()));
        return length;
    }
};