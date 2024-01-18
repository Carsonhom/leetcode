class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        return searchHelper(nums, target, start, end);
    }

    int searchHelper(vector<int>& nums, int target, int start, int end)
    {

        if (start > end) {  // base case for when target is not found
            return -1;
        }

        if (nums[start] == target)  // base case
            return start;
        if (nums[end] == target)  // base case
            return end;

        int mid = (start + end) / 2;

        if (nums[mid] == target)  // base case
            return mid;

        if (nums[start] <= nums[mid]) // left side is sorted
        {
            if(nums[start] <= target && target <= nums[mid]) // target is in sorted side
                return searchHelper(nums, target, start, mid - 1);
            else // target is not in sorted side
                return searchHelper(nums, target, mid + 1, end);
        }
        else // right side is sorted
        {
            if(nums[mid + 1] <= target && target <= nums[end]) // target is in sorted side
                return searchHelper(nums, target, mid + 1, end);
            else // target is not in sorted side
                return searchHelper(nums, target, start, mid - 1);
        }

    }
};
