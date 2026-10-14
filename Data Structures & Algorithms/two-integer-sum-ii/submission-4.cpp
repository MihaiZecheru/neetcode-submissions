class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start_index = 0;
        int end_index = numbers.size() - 1;
        while (numbers[start_index] + numbers[end_index] != target)
        {
            if (numbers[start_index] + numbers[end_index] < target)
            {
                ++start_index;
            }
            else
            {
                --end_index;
            }
        }

        // To account for the array being 1-indexed
        return { start_index + 1, end_index + 1 };
    }
};
