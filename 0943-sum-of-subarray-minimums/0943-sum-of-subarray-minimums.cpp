class Solution {
public:

    // T.C. is O(N*N)

    // int sumSubarrayMins(vector<int>& arr) {
    //     long long total = 0;
    //     long long MOD = 1e9+7;
    //     int n = arr.size();
    //     for(int i = 0 ; i< n; i++){
    //         int currMin = arr[i];
    //         for(int j = i ; j< n; j++){
    //             currMin = min(currMin, arr[j]);
    //             total += currMin;
    //         }
    //     }
    //     return total%MOD;
    //  }

    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();

            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
     vector<int> findPSE(vector<int>& arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i = 0; i< n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();

            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        long long totalSum = 0;
        long long MOD = 1e9+7;
        vector<int> NSE = findNSE(arr);
        vector<int> PSE = findPSE(arr);
        int left, right;
        for(int i = 0 ; i< arr.size(); i++){
            left = i - PSE[i];
            right = NSE[i] - i;
            totalSum = (totalSum + ((long long)left*right*arr[i])%MOD)%MOD;
        }
        return totalSum;
    }
    
};