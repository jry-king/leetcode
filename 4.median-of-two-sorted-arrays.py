from typing import List

# use the approach in solution, trying to divide all numbers in given lists into two equal length subsets with one always greater than the other
# since given lists are sorted, just find a pair of proper numbers (i,j),
# in which i + j = m - i + n - j (+ 1), and b[j-1] < a[i], a[i-1] < b[j]
# so just find i in [0,m] such that b[j-1] < a[i], a[i-1] < b[j] where j = (m + n + 1) // 2 - i
# O[log(min(m,n))] time complexity and O[1] space complexity
# 96 ms, faster than 70.65%
# 13.4 MB, less than 5.11%


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # distinguish the shorter list from the longer one
        # to ensure j is always positive
        a, b = sorted((nums1, nums2), key=len)
        m, n = len(a), len(b)

        # the middle index in the overall list (which means sorted(nums1+nums2), denoted as nums below)
        # if m+n is odd, then nums[half-1] is needed
        # if even, then (nums[half-1]+nums[half])/2
        half = (m + n + 1) // 2
        low, high = 0, m

        while low <= high:
            i = (low + high) // 2
            j = half - i

            # i is too small and can be increased
            if (i < m and b[j - 1] > a[i]):
                low = i + 1
            # i is too large and can be decreased
            elif (i > 0 and a[i - 1] > b[j]):
                high = i - 1
            # i is proper now, deal with some edge values
            else:
                # find nums[half-1] (left_max)
                if (i == 0):
                    left_max = b[j - 1]
                elif (j == 0):
                    left_max = a[i - 1]
                else:
                    left_max = max(a[i - 1], b[j - 1])
                if ((m + n) % 2):
                    return left_max
                # find nums[half] (right_min)
                if (i == m):
                    right_min = b[j]
                elif (j == n):
                    right_min = a[i]
                else:
                    right_min = min(a[i], b[j])
                return (left_max + right_min) / 2.0
