class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            // here we are checking for elemment val in nums if it doesnt equal to array then we copy into the kth positon which is staring from zero in nums array 
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;        
    }
};