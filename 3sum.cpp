class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) { // Fix one element in place, then problem becomes 2sum
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate elements

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) // Skip duplicates
                        left++;   
                    while (left < right && nums[right] == nums[right - 1]) // Skip duplicates
                        right--; 
                    left++; right--;
                } else if (sum < 0) { // increase sum
                    left++;
                } else { // decrease sum
                    right--;
                }
            }
        }

        return result;
    }
};
