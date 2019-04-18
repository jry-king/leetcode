#include <string>
using namespace std;

#include <limits.h>

class Solution {
public:
    int myAtoi(string str) 
    {
        int ans = 0;
        bool sign = true;   // positive or negative
        bool num = false;   // whether the conversion has started
        for (int i = 0; i < str.length(); i++)
        {
            // skip prefix spaces
            if (!num && str[i] == ' ')
            {
                continue;
            }
            // identify negative number
            // '-' is valid only before 
            if (str[i] == '-' && !num)
            {
                sign = false;
                num = true;
                continue;
            }
            else if (str[i] == '+' && !num)
            {
                sign = true;
                num = true;
                continue;
            }
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
                int num = str[i] - '0';
                if (sign && ans > INT_MAX - num)
                {
                    return INT_MAX;
                }
                else if (!sign && ans < INT_MIN + num)
                {
                    return INT_MIN;
                }
                if (sign)
                {
                    ans += num;
                }
                else
                {
                    ans -= num;
                }
            }
            else
            {
                return ans;
            }
        }
        return ans;
    }
};