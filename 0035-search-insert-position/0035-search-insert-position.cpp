class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        int mid;
        if(nums[end-1]<target){
            return end;
        }
        while(start<=end){
            mid = start+(end-start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = mid+1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            
        }
        return start;
        
        
    }
};