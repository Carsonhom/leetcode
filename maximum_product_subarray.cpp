class Solution {
public:
    int maxProduct(vector<int>& nums) { // Kadanes algorithm
        if (nums.size() == 0) 
            return 0;

        int maxProduct = INT_MIN; // maximum product subarray
        int product = 1; // product so far
        for (int i = 0; i < nums.size(); i++) // calculate max product traversing left to right
        {
            product *= nums[i];
            maxProduct = max(product, maxProduct); // update maxproduct
            if (product == 0) // deal with 0s in array
                product = 1;
        }

        product = 1;
        for (int j = nums.size() - 1; j >= 0; j--) // calculate max product traversing right to left
        {
            product *= nums[j];
            maxProduct = max(product, maxProduct);
            if (product == 0)
                product = 1;
        }
        return maxProduct;
    }


};
