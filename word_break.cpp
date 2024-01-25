class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0)
            return false;

        vector<bool> memo(s.size(), false); // memo table, memo[i] is true if substring ending with it can be broken up

        for (int i = 0; i < s.size(); i++) 
        {
            for (const string& word : wordDict) 
            {
                if (i >= word.size() - 1) // Check if 'word' can fit in the substring ending at 'i'
                {
                    int start = i - word.size() + 1; // Calculate the start index for substring comparison
                    if (s.substr(start, word.size()) == word) // Compare substring with the word
                    {
                        // Check if this is the start of the string or the substring before 'start' can be broken
                        if (start == 0 || memo[start - 1]) 
                        {
                            memo[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        return memo[s.size() - 1];

    }
};
