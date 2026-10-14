class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int i = 0; i < nums.size(); ++i)
        {
            hashset.insert(nums[i]);
        }

        // <starting_num, streak_count>
        vector<int> starts;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!hashset.contains(nums[i] - 1))
            {
                starts.push_back(nums[i]);
            }
        }

        int largest_count = 0;
        for (int i = 0; i < starts.size(); ++i)
        {
            int c = 1;
            while (hashset.contains(starts[i] + c))
            {
                ++c;
            }

            if (c > largest_count)
            {
                largest_count = c;
            }
        }

        return largest_count;
    }
};
