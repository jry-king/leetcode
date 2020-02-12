#include <iostream>
#include <vector>
using namespace std;

/*
 * use the approach in solution, trying to divide all numbers in given lists into two equal length subsets with one always greater than the other
 * since given lists are sorted, just find a pair of proper numbers (i,j),
 * in which i + j = m - i + n - j (+ 1), and b[j-1] < a[i], a[i-1] < b[j]
 * so just find i in [0,m] such that b[j-1] < a[i], a[i-1] < b[j] where j = (m + n + 1) // 2 - i
 * O[log(min(m,n))] time complexity and O[1] space complexity
 * 12 ms, faster than 98.34%
 * 9.7 MB, less than 70.1%
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = nums1.size() <= nums2.size() ? nums1 : nums2;
        vector<int>& b = nums1.size() <= nums2.size() ? nums2 : nums1;
        int m = int(a.size());
        int n = int(b.size());
        int half = (m + n + 1) / 2;
        int low = 0;
        int high = m;
        int i = 0;
        int j = 0;
        int left_max = 0;
        int right_min = 0;

        while (low <= high)
        {
            i = (low + high) / 2;
            j = half - i;
            if (i < m && b[j - 1] > a[i])
            {
                low = i + 1;
            }
            else if (i > 0 && a[i - 1] > b[j])
            {
                high = i - 1;
            }
            else
            {
                if (0 == i)
                {
                    left_max = b[j - 1];
                }
                else if (0 == j)
                {
                    left_max = a[i - 1];
                }
                else
                {
                    left_max = max(a[i - 1], b[j - 1]);
                }
                if ((m + n) % 2)
                {
                    return left_max;
                }
                if (i == m)
                {
                    right_min = b[j];
                }
                else if (j == n)
                {
                    right_min = a[i];
                }
                else
                {
                    right_min = min(a[i], b[j]);
                }
                return (left_max + right_min) / 2.0;
            }
        }
        return 0;
    }
};