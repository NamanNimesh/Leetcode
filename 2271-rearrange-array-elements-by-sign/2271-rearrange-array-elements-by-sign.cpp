class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,0);
        int second = 1;
        int first = 0;
        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i] > 0){
                ans[first] = nums[i];
                first +=2; 
            }
            if(nums[i]<0){
                ans[second] = nums[i];
                second +=2;
            }
        }
        return ans;
    }
};