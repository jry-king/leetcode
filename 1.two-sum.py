from typing import List

# Brute force approach, for every number just look up for its complement in following numbers
# 5864 ms, faster than 15.28%
# 13.7 MB, less than 80.46%


'''
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums)):
                if (nums[i] + nums[j] == target and i != j):
                    return [i, j]
'''

# One-pass hash table, solution 3
# 40 ms, faster than 97.99%
# 14.1 MB, less than 63.49%


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = dict()
        for i in range(0, len(nums)):
            complement = target - nums[i]
            if (complement in hashmap):
                return [hashmap[complement], i]
            hashmap[nums[i]] = i
