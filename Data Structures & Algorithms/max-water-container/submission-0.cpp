class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start_index = 0;
        int end_index = heights.size() - 1;
        int max_area = 0;
        while (start_index < end_index)
        {
            int a = area(heights[start_index], heights[end_index], end_index - start_index);
            if (a > max_area) max_area = a;
            if (heights[start_index] < heights[end_index])
            {
                ++start_index;
            }
            else
            {
                --end_index;
            }
        }
        return max_area;
    }

    int area(int h1, int h2, int width)
    {
        return width * min(h1, h2);
    }
};
