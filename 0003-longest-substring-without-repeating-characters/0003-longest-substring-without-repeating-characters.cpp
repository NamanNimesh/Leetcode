class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for(int i = 0; i<256;i++){
            hash[i] = -1;
        }
        int n = s.size();
        int left = 0, right = 0, maxLen = 0, len = 0;
        while(right<n){
            if(hash[s[right]] != -1){
                if(hash[s[right]] >= left){
                    left = hash[s[right]]+1;
                }
            }
            len = right - left +1;
            maxLen = max(len,maxLen);
            hash[s[right]] = right;
            right++;
        }
        return maxLen;
        
    }
};