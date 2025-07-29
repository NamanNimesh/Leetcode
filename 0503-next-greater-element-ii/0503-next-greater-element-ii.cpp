// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> NGE(n);
//         stack<int> st;
//         for(int i = (2*n)-1; i >=0; i--){
//             while(!st.empty() && st.top() <=nums[i%n]){
//                 st.pop();
//             }
//             if(i<n){
//                 NGE[i] = st.empty() ? -1 : st.top();
//             }

//             st.push(nums[i%n]);
//         }
//         return NGE;
//     }
// };
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //Circular Array :- means entire array(size) from that element

        // int n = nums.size();
        // vector<int>ans(n,-1);
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < i + n; j++){
        //         int ind = j % n;
        //         if(nums[ind] > nums[i]){
        //             ans[i] = nums[ind];
        //             break;
        //         }
        //     }
        // }
        // return ans;

        // Using Monotonic stack :-
        // int n = nums.size();
        // stack<int>st;
        // vector<int>ans(n,-1);
        // for(int i = 2*n- 1; i >= 0; i--){
        //     while(!st.empty() && st.top() <= nums[i%n]){
        //         st.pop();
        //     }
        //     if(i < n){
        //         if(!st.empty()){
        //             ans[i] = st.top();
        //         }
        //     }
        //     st.push(nums[i]);
        //     // It reaches to the same element at original i.
        // }
        // return ans;

        // int n = nums.size();
        // vector<int>ans;
        // for(int i = 0; i < n; i++){
        //     bool isNGE = false;
        //     for(int j = i+1; j < (i + n); j++){
        //         if(nums[j % n] > nums[i]){
        //             ans.push_back(nums[j%n]);
        //             isNGE = true;
        //             break;
        //         }
        //     }
        //     if(isNGE == false){
        //         ans.push_back(-1);
        //     }
        // }
        // return ans;


        int n = nums.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i = 2*n-1; i >= 0; i--){
            while(!st.empty() && nums[i%n] >= st.top()){
                st.pop();
            }
            if(i < n && (!st.empty()) && nums[i%n] < st.top()){
                ans[i] = st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};