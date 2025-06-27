class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;

        for(auto i : nums){
            mpp[i]++;
        }
        for(int i = 1 ; i<=nums.size();i++){
            if(mpp[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};