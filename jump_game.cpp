class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), false); // memo[i] = true if it is reachable
        memo[0] = true;

        for (int i = 0; i < nums.size(); i++)
        {
            if (memo[i] == true) // array element i is reachable
            {
                for (int j = i + 1; j <= i + nums[i] && j < nums.size(); j++) // set array elements i + nums[i] to true
                {
                    memo[j] = true;
                }
            }
        }
        return memo[nums.size() - 1]; 
    }
};
