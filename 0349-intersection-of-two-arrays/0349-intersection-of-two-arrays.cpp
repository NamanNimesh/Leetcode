class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(auto it : nums1){
            mpp[it]++;

        }
        for(int i = 0; i< nums2.size();i++){
            if(mpp[nums2[i]] > 0 ){
                ans.push_back(nums2[i]);
                mpp[nums2[i]]= 0;
            }
        }

        return ans;
    }
};