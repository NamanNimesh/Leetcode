class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int countZero = 0;
        int n = nums.size();
        int len = 0;
        int maxLen = 0;

        while(right<n){
            if(nums[right] == 0){
                countZero++;
            }
            while(countZero > k){
                if(nums[left] == 0){
                    countZero--;
                }
                left++;
            }
            len = right -left +1;
            maxLen = max(maxLen,len);
            right++;
            

        }
        return maxLen;
    }
};