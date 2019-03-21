# brute force, examine longest substring starting from each character and compare their lengths
# 576 ms, faster than 15.2%
# 13.1 MB, less than 5.51%
'''class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 0
        substring = ""
        for i in range(0, len(s)):
            substring = s[i]
            j = i + 1
            while (j < len(s) and s[j] not in substring):
                substring += s[j]
                j += 1
            length = max(length, len(substring))
        return length'''

# optimized sliding window, add character to substring one by one, 
# and if duplicate character appears, truncate the former part of the substring divided by this character, then add this character to the end
# 80 ms faster than 83.66%
# 13.3 MB, less than 5.05%
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 0
        substring = ""
        for i in range(0, len(s)):
            if (s[i] in substring):
                length = max(length, len(substring))
                substring = substring.split(s[i])[-1] + s[i]
            else:
                substring += s[i]
        length = max(length, len(substring))
        return length