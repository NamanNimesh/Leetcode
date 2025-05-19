class Solution {
private:
    int binarySearch(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int trackStart, trackEnd;

        trackStart = binarySearch(nums, target);
        trackEnd = binarySearch(nums, target + 1) - 1;
        if (trackStart < nums.size() && nums[trackStart] == target) {
            return {trackStart, trackEnd};
        }
        return {-1, -1};
    }
};