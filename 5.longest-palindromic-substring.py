# first trial, similar as solution 4
# pick letter one by one as centers and expand, checking whether letters at both sides are the same
# and detect string composed of identical letters to avoid redundant check
# O[n**2] time complexity and O[1] space complexity
# 160 ms, faster than 89.58%
# 13.2 MB, less than 25.1%


class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        low_index = 0
        for i in range(len(s)):
            if (i + 1 < len(s) and s[low_index] == s[i + 1]):
                continue
            temp = 0
            while (low_index - temp >= 0 and i + temp < len(s) and s[low_index - temp] == s[i + temp]):
                if (len(res) < i - low_index + 1 + 2 * temp):
                    res = s[low_index - temp:i + temp + 1]
                temp += 1
            low_index = i + 1
        return res
