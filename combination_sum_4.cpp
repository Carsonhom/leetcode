class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, 0); // nums[i] = number of ways to get to i using numbers in the array
        memo[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int num : nums)
            {
                if (i - num >= 0)
                    memo[i] += memo[i - num];
            }
        }
        return memo[target];
    }
};
