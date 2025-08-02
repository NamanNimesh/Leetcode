class Solution {
public:


    //long long subArrayRanges(vector<int>& nums) {
        // long long total = 0;

        // for(int i = 0; i< nums.size(); i++){
        //     int currMin = nums[i];
        //     int currMax = nums[i];
        //     for(int j = i; j<nums.size(); j++){
        //         currMin = min(currMin,nums[j]);
        //         currMax = max(currMax,nums[j]);
        //         total = total + (currMax-currMin);
        //     }
        // }
        // return total;
    //     stack<int> st;
    //     for(int i = 0; i< nums.size(); i++){

    //     }
    // }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                res += (long long)nums[mid] * (mid - left) * (i - mid);
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                res -= (long long)nums[mid] * (mid - left) * (i - mid);
            }
            st.push(i);
        }
        return res;
    }
};