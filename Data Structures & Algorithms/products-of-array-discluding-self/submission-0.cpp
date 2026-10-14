class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> product_except_self(n, 1);
        map<int, int> prefix_map {};
        
        // Loop over to get the prefix product
        prefix_map[0] = 1;
        int prefix_product = nums[0];
        for (int i = 1; i < n; ++i)
        {
            prefix_map[i] = prefix_product;
            prefix_product *= nums[i];
        }

        // Loop in reverse to get the suffix product
        int suffix_product = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            product_except_self[i] = prefix_map[i] * suffix_product;
            suffix_product *= nums[i];
        }

        return product_except_self;
    }
};
