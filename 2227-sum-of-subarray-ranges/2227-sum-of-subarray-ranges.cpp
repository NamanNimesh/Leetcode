class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long total = 0;

        for(int i = 0; i< nums.size(); i++){
            int currMin = nums[i];
            int currMax = nums[i];
            for(int j = i; j<nums.size(); j++){
                currMin = min(currMin,nums[j]);
                currMax = max(currMax,nums[j]);
                total = total + (currMax-currMin);
            }
        }
        return total;
        
        
    }
};