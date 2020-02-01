#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        // if p is empty, then only an empty s can match it
        if (p == "")
        {
            return (s == "");
        }
        // if s is empty and p is not, then they match only if every letter in p is followed by *
        else if (s == "")
        {
            for (int i = 0; i < p.length(); i += 2)
            {
                if (p[i] == '*' || p[i+1] != '*')
                {
                    return false;
                } 
            }
            return true;
        }
        else
        {
            if (p[1] != '*')
            {
                if (s[0] != p[0] && p[0] != '.')
                {
                    return false;
                }
                return isMatch(s.substr(1), p.substr(1));
            }
            else
            {
                int i;
                bool ans = isMatch(s.substr(0), p.substr(2));
                for (i = 0; s[i] == p[0] || (p[0] == '.' && i < s.length()); i++)
                {
                    ans = ans || isMatch(s.substr(i+1), p.substr(2));
                }
                return ans;
            }
        }
    }
};