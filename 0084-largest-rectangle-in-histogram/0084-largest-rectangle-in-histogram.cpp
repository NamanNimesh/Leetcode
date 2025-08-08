class Solution {
public:
    vector<int> findNSE(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> nse(n,0);
        for(int i =n-1 ;i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
            
        }
        return nse;
    }
    vector<int> findPSE(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> pse(n,0);
        for(int i =0 ;i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
            
        }
        return pse;
    }


    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        vector<int> NSE = findNSE(heights);
        vector<int> PSE = findPSE(heights);
        for(int i = 0; i < heights.size(); i++ ){
            maxi = max(maxi,(heights[i] * (NSE[i] -PSE[i] -1)));

        }
        return maxi;
    }
};