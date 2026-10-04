class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int lo, int hi) {
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (target <= nums[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return (nums[lo] == target) ? lo : -1; 
    }

    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        // Find pivot point for rotation, stored in 'lo'.
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (nums[lo] == target) { return lo; }
        if (target > nums[nums.size()-1]) {
            return binarySearch(nums, target, 0, lo - 1);
        } else {
            return binarySearch(nums, target, lo, nums.size() - 1);
        }
    }
};
