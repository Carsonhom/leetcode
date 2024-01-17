class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }

    int maxSubArrayHelper(vector<int>& nums, int start, int end) // Divide and conquer
    {
        if (start == end)
        {
            return nums[start];
        }

        int mid = (start + end) / 2;

        return max(maxSubArrayHelper(nums, start, mid),
                    max(maxSubArrayHelper(nums, mid + 1, end), maxMiddleSubArray(nums, start, mid, end)));
    }

    int maxMiddleSubArray(vector<int>& nums, int start, int mid, int end) // calculate subarray sum from array middle point
    {
        int leftSum = INT_MIN; // maximum subarray from left side of midpoint
        int sum = 0;
        for (int i = mid; i >= start; i--)
        {
            sum += nums[i];
            if (sum > leftSum)
                leftSum = sum;
        }

        int rightSum = INT_MIN; // maximum subarray from right side of midpoint
        sum = 0;
        for (int j = mid + 1; j <= end; j++)
        {
            sum += nums[j];
            if (sum > rightSum)
                rightSum = sum;
        }

        return leftSum + rightSum;
    }
};
