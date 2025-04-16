class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> count;

        //count for charcter in string s
        for(auto i : s)
        {
            count[i]++;
        }
        //count for charcter in string t
        for(auto i : t)
        {
            count[i]--;
        }

        for(auto i : count)
        {
            if(i.second != 0)
            {
                return false;
            }
        }
        return true;

        
        
        
    }
};