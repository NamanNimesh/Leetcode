class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int> temp(k);

        // store last k elements
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // shift remaining elements right
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }

        // copy temp to front
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
