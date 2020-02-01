#include <iostream>
#include <vector>
#include <map>
using namespace std;

// One-pass hash table, solution 3
// 12 ms, faster than 67.90%
// 10.1 MB, less than 54.22%

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if(hashmap.find(complement) != hashmap.end())
            {
                res.push_back(hashmap[complement]);
                res.push_back(i);
                return res;
            }
            hashmap[nums[i]] = i;
        }
        return res;
    }
};
