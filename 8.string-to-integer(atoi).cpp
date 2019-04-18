#include <string>
using namespace std;

/*
 * O[n] time complexity and O[1] space complexity
 * 8 ms, faster than 99.67%
 * 8.5 MB, less than 99.8%
 */
#include <limits.h>

class Solution {
public:
    int myAtoi(string str) 
    {
        int ans = 0;
        bool sign = true;   // positive or negative
        bool num = false;   // whether the conversion has started (also used to check when the conversion ends)
        for (int i = 0; i < str.length(); i++)
        {
            // skip prefix spaces
            if (!num && str[i] == ' ')
            {
                continue;
            }
            // identify negative number
            // '-' is valid only before digits
            if (str[i] == '-' && !num)
            {
                sign = false;
                num = true;
                continue;
            }
            // identify plus sign, valid only before digits
            else if (str[i] == '+' && !num)
            {
                sign = true;
                num = true;
                continue;
            }
            // process digits, detect overflow beforehand
            else if (isdigit(str[i]))
            {
                num = true;
                if (sign && ans > INT_MAX/10)
                {
                    return INT_MAX;
                }
                else if (!sign && ans < INT_MIN/10)
                {
                    return INT_MIN;
                }
                ans *= 10;
                int number = str[i] - '0';
                if (sign && ans > INT_MAX - number)
                {
                    return INT_MAX;
                }
                else if (!sign && ans < INT_MIN + number)
                {
                    return INT_MIN;
                }
                if (sign)
                {
                    ans += number;
                }
                else
                {
                    ans -= number;
                }
            }
            // process ends when reach invalid character or reach nondigit with the num flag on
            else
            {
                return ans;
            }
        }
        // process ends when reach the end of the string
        return ans;
    }
};