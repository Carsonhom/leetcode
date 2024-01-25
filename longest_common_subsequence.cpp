class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() == 0 || text2.size() == 0)
            return 0;
        
        vector<vector<int>> memo(text1.size() + 1, vector<int>(text2.size() + 1, 0)); // 2d memo table

        for (int i = 1; i < text1.size() + 1; i++) // iterate over memo table
        {
            for (int j = 1; j < text2.size() + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1]) // matching characters
                {
                    memo[i][j] = memo[i - 1][j-1] + 1;
                }
                else // characters do not match
                {
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                }
            }
        }

        return memo[text1.size()][text2.size()];
    }
};
