class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) // initialize first element
        {
            product[0] = product[0] * nums[i];
        }

        for (int j = 1; j < nums.size(); j++) 
        {
            if(nums[j] != 0) // if current element is not 0 set it equal to previous product, divide by current element and multiply by previous element
                product[j] = (product[j - 1] / nums[j]) * nums[j - 1];
            else // prevent division by 0, manually calculate current emelent's product
            {
                for (int k = 0; k < nums.size(); k++)
                {
                    if (k != j)
                        product[j] = product[j] * nums[k];
                }
            }
        }
        return product;
    }
};
