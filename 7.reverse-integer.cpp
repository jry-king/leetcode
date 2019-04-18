/*
 * Pop and push digits while checking overflow beforehand.
 * Same as approach 1.
 * O[log(x)] time complexity and O[1] space complexity
 * 4 ms, faster than 100%
 * 8.1 MB, less than 99.8%
 */
#include <limits.h>

class Solution {
public:
    int reverse(int x) 
    {
        // add up digits one by one
        int temp = x;
        int ans = 0;
        while (temp != 0)
        {
            // return 0 when overflow
            if (ans > (INT_MAX/10) || ans < (INT_MIN/10))
            {
                return 0;
            }
            ans *= 10;
            // return 0 when overflow
            if ((x > 0 && ans > (INT_MAX-temp%10)) || (x < 0 && ans < (INT_MIN-temp%10)))
            {
                return 0;
            }
            ans += temp % 10;
            temp /= 10;
        }

        return ans;
    }
};