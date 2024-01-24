class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, amount + 1); // memoization table, memo[i] = # min number of coins
        memo[0] = 0; // base case

        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                memo[i] = min(memo[i], memo[i - coin] + 1); // update memo table
            }
        }
        if (memo[amount] > amount) // no combination of change
            return -1;
        else 
            return memo[amount];
    }
};
