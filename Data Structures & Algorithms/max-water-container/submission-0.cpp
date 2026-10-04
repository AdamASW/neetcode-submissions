class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int max_area = 0;
        while (l < r) {
            int height_l = heights[l], height_r = heights[r];
            int curr_area = (r-l)*(min({height_l, height_r}));
            max_area = (curr_area > max_area) ? curr_area : max_area;
            if (height_l < height_r) { l++; }
            else { r--; }
        }
        return max_area;
    }
};
