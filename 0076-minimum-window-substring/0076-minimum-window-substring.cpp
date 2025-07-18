// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int l = 0, r = 0, cnt = 0, sIndex = -1;
//         int minLen = INT_MAX;
//         int n = s.length(), m = t.length();
//         int hash[256] = {0};
//         for(int i = 0; i< m ;i++){
//             hash[t[i]]++;
//         }
//         while(r<n){
//             if(hash[s[r]] > 0 ){
//                 cnt = cnt+1;
//                 hash[s[r]]--;
//             }
//             while(cnt == m){
//                 if((r-l+1) < minLen){
//                     minLen = r-l+1;
//                     sIndex = l;
//                 }
//                 hash[s[l]]++;
//                 if(hash[s[l]] > 0){
//                     cnt++;
                    
//                 }
//                 l++;
                
//             }
//             r++;
//         }
//         return sIndex == -1 ? "" : s.substr(sIndex, minLen);
//     }
// };
class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, cnt = t.size(), sIndex = -1;
        int minLen = INT_MAX;
        int hash[256] = {0};

        // Build frequency map for characters in t
        for (char c : t) {
            hash[c]++;
        }

        while (r < s.size()) {
            // If current char is needed, decrement count
            if (hash[s[r]] > 0) {
                cnt--;
            }
            // Reduce frequency in hash whether needed or not
            hash[s[r]]--;

            // Try to shrink window if all characters matched
            while (cnt == 0) {
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }

                // Before moving left, restore the character
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt++; // One required char is now missing
                }
                l++;
            }
            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};