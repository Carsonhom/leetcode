class Solution {
vector<int> memo;

public:
    int climb(int n) {
        if (n == 0 || n == 1) 
            return 1;
        else if (memo[n] != -1)
            return memo[n];
        else
        {
            memo[n] = climb(n - 1) + climb(n - 2);
        }
        return memo[n];
    }

    int climbStairs(int n) {
        memo.resize(n + 1, -1);
        return climb(n);
    }
};
