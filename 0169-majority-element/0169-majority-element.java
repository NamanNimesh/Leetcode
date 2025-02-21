class Solution {
    public int majorityElement(int[] nums) {
        int candidate = nums[0];
        int count = 1;

        // Phase 1: Find the candidate element
        for (int i = 1; i < nums.length; i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Phase 2: Return the candidate (majority element)
        return candidate;
    }
}