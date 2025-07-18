class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return totalCount(nums, k) - totalCount(nums, k-1);
    }


    int totalCount(vector<int>& nums, int k){
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;

        for(r = 0; r< nums.size(); r++){
            if(mpp[nums[r]] == 0){
                k--;
            }
            mpp[nums[r]]++;
            while(k < 0){
                mpp[nums[l]]--;
                if(mpp[nums[l]]== 0){
                    k++;
                }
                l++;
            }
            cnt += r-l+1;

        }
        return cnt;
    }
};