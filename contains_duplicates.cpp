class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicates; // unordered_set cannot contain duplicates
        for (int num : nums)
        {
            if (duplicates.find(num) == duplicates.end()) // element is distinct
            {
                duplicates.insert(num);
            }
        }
        return (duplicates.size() != nums.size());
    }
};
