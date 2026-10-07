class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       std::map<int, bool> seen;
       for (int i = 0; i < nums.size(); ++i)
       {
            if (seen[nums[i]]) return true;
            seen[nums[i]] = true;
       }
       return false;
    }
};