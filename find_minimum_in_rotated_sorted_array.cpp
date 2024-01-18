class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        return findMinHelper(nums, start, end);
    }

    int findMinHelper(vector<int>& nums, int start, int end)
    {
        if (start == end)
            return nums[start];
        int mid = (start + end) / 2;

        if (nums[mid] >= nums[end]) // left half is sorted
        {
            return findMinHelper(nums, mid + 1, end);
        }
        else 
            return findMinHelper(nums, start, mid);
    }
};
