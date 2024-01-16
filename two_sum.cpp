#include <algorithm>
#include <unordered_map>
class Solution {
public:
    // Naive implementation
    // nested loop through all elements to find two that add to target
    // vector<int> twoSum(vector<int>& nums, int target) 
    // {
    //     vector<int> solution(2);
    //     for (int i = 0; i < nums.size(); i++) 
    //     {
    //         for (int j = i + 1; j < nums.size(); j++)
    //         {
    //             if (nums[i] + nums[j] == target)
    //             {
    //                 solution = {i, j};
    //             }
    //         }
    //     }
    //     return solution;
    // }

    // Optimized solution
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hashTable(nums.size()); // key is the number, value is index
        vector<int> solution(2);
        for (int i = 0; i < nums.size(); i++)
        {
            int compliment = target - nums[i];
            if (hashTable.find(compliment) != hashTable.end()) // check for compliment in hash map
            {
                solution =  {i, hashTable[compliment]};
            }
            hashTable[nums[i]] = i; // store number and index in hash table
        }
        return solution;
    }
};
