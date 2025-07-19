class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), j=0, max_freq=0, re_max=0;
        vector<int>freq(26, 0);
        char max_freq_word;
        for(int i=0; i<n; i++)
        {
            int num = s[i]-'A';
            max_freq = max(max_freq, ++freq[num]);
            while(i-j+1-max_freq>k)
            {
                freq[s[j]-'A']--;
                j++;
            }
            re_max=max(re_max, i-j+1);
        }
        return re_max;
    }
};