/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int k=nums.size()-1;
        for(int i=0;i<=k;i++)
        {
            for(int j=i+1;j<=k;j++)
            {
                if(nums[i]+nums[j]==target)
                {res.push_back(i);
                res.push_back(j);
                                }
            }
        }
        return res;
    }
};

// @lc code=end

