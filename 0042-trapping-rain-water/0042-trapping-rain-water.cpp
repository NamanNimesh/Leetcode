 class Solution {
 public:

//     vector<int> prefixMax(vector<int> &height){
//         int n = height.size();
//         vector<int> prefix(n);
//          prefix[0] = height[0];
//         for(int i = 1; i<n; i++){
//             prefix[i] = max(prefix[i-1],height[i]);
//         }
//         return prefix;
//     }
//     vector<int> suffixMax(vector<int> &height){
//         int n = height.size();
//         vector<int> suffix(n);
//          suffix[n-1] = height[n-1];
//         for(int i = n-2; i>= 0; i--){
//             suffix[i] = max(suffix[i+1],height[i]);
//         }
//         return suffix;
//     }
//     int trap(vector<int>& height) {
//         int totalWater = 0;
//         vector<int> leftMax = prefixMax(height);
//         vector<int> rightMax = suffixMax(height);
//         for(int i = 0; i< height.size();i++){
//             totalWater += min(leftMax[i],rightMax[i])-height[i];
           
//         }

//         return totalWater;
//     }

    int trap(vector<int>& height){
        int n = height.size();
        int lMax = 0,rMax = 0,total = 0;
        int l = 0, r = n-1;
        while(l<r){
            if(height[l] <= height[r]){
                if(lMax > height[l]){
                    total += lMax-height[l];
                }
                else{
                    lMax = height[l];
                }
                l++;
            }
            else{
                if(rMax>height[r]){
                    total += rMax-height[r];
                }
                else{
                    rMax = height[r];
                }
                r--;
            }
        }
        return total;
    }




};