/*
 * To avoid using string or overflow, revert lower half of the number and compare with the upper half.
 * Same as approach 1.
 * O[log(x)] time complexity and O[1] space complexity
 * 32 ms, faster than 99.53%
 * 8.1 MB, less than 99.78%
 */
class Solution {
public:
    bool isPalindrome(int x) 
    {
        // negative sign prevent the number from being palindromic
        if (x < 0)
        {
            return false;
        }
        
        // 0 is a palindrome
        if (x == 0)
        {
            return true;
        }

        // positive numbers
        else
        {
            int a = x;
            int b = 0;
            // just revert lower half, reversion completes when original number is smaller than reversion result
            while (a > b)
            {
                b *= 10;
                b += a % 10;
                // palindrome with a center of a single letter
                if (a == b)
                {
                    return true;
                }
                // numbers ending with 0 is not palindromic
                // since we do not denote a number with 0 as the first digit
                if (b == 0)
                {
                    return false;
                }
                a /= 10;
                // palindrome with a center of a pair of identical letters
                if (a == b)
                {
                    return true;
                }
            }
            return false;
        }
    }
};