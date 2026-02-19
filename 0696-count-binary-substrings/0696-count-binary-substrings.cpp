class Solution {
public:
    int countBinarySubstrings(string s) {
       int cur = 1, prev = 0, ans = 0;
       for(int i = 1; i< s.length();i++){
        if(s[i] == s[i-1]){
            cur++;
        }
        else{
            ans += min(cur,prev);
            prev = cur;
            cur = 1;
        }
       }
       return ans+min(cur,prev);
    }
};