class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 1)); // memo[i][j] = number of ways for the robot to get to tile i.j

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
            }
        }
    return memo[m - 1][n - 1];
    }

    
};
