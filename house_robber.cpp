class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int> memo(nums.size(), 0); // memo[i] = amount of money that can be stolen from i houses
        memo[0] = nums[0]; // base case
        memo[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            memo[i] = max(nums[i] + memo[i - 2], memo[i - 1]); // choose to rob house i or skip
        }

        return memo[nums.size() - 1]; // final answer
    }
};
