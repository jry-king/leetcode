# Brute force approach, for every number just look up for its complement in following numbers
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0,len(nums)):
            for j in range(i+1,len(nums)):
                if (nums[i] + nums[j] == target and i != j):
                    return [i, j]