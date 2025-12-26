class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    // What we are doing is that starting at index 2 because there is always 2 elements present in the array and comparing with the -2 index for removing any type of buffer overflow
       if(nums.size()<=2) return nums.size();
       int k = 2;
       for(int i=2; i< nums.size();i++){
        if(nums[i] != nums[k-2]){
            nums[k]= nums[i];
            k++;
        }
       }
       
       return k;
    }
};