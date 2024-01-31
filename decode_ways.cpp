class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.size() + 1, 0); // memo[i] = # of decode ways for i # of characters
        if (s[0] == '0')
            return 0;
        memo[0] = 1; // base case
        memo[1] = 1;
            
        for (int i = 2; i <= s.size(); i++)
        {
            if (s[i - 1] != '0') // 1 digit numbers
                memo[i] += memo[i - 1];

            int twoDigit = stoi(s.substr(i - 2, 2)); // 2 digit numbers
            if (twoDigit >= 10 && twoDigit <= 26)
                memo[i] += memo[i - 2];
        }
        return memo[s.size()];
    }
};
