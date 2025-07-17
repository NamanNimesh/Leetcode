class Solution {
public:
        int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums, k) - count(nums, k - 1);
    }

    int count(vector<int>& nums, int goal) { 
         int cnt = 0;
        int sum = 0;
        int l = 0, r = 0;
        if(goal< 0) return 0;
        for(int r = 0 ; r< nums.size(); r++){
            sum = sum + nums[r]%2;
            while(sum > goal){
                sum = sum - nums[l]%2;
                l++;
            }
            cnt  = cnt +(r-l+1);
            
        }
        return cnt;
     }
};