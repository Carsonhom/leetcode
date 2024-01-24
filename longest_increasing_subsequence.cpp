#include <algorithm>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        vector<int> memo(nums.size(), 1); // memo table, memo[i] = longest increasing subsequence ending here

        int start;
        for (int i = 1; i < nums.size(); i++) // ending element in subsequence
        {
            for (int j = 0; j < i; j++) // compare to earlier elements in nums vector
            {
                if (nums[i] > nums[j])
                    memo[i] = max(memo[i], memo[j] + 1); // update memo table
            }
        }
        return *max_element(memo.begin(), memo.end());
    }
};
