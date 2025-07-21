class Solution {
public:
    void print(vector<int>& nums, vector<vector<int>>& ans, vector<int>& res, int i) {
        if (i == nums.size()) {
            ans.push_back(res);
            return;
        }

        res.push_back(nums[i]);
        print(nums, ans, res, i + 1);
        res.pop_back();

       
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[i]) {
            idx++;
        }
        print(nums, ans, res, idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(), nums.end());
        print(nums, ans, res, 0);
        return ans;
    }
};