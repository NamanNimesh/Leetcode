class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        //here is a small edge case of buffer overflow so you should start with 1 because first element is always unique
        int k =1;
        for(int i=1; i< nums.size();i++){
           if(nums[i] != nums[i-1]){
            nums[k]= nums[i];
            k++;
           }
        }
        return k;
    }
};