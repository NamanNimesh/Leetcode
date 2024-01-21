class Solution {
public:
    int compress(vector<char>& chars) {

        int i =0 ;
        int ansindex = 0;
        int n = chars.size();

        while(i<n)
        {
            int j = i+1;
            while(j<n && chars[i] == chars[j])
            {
                j++;
            }

            //yha kab aayenge
            //ya tho vector poora traverse krdia
            //ya fer new/different character encounter kia hai

            //oldchar store krlo
            chars[ansindex++] = chars[i];

            int count = j-i;

            if (count>1)
            {
                //converting counting into string digit and saving in answer
                string cnt = to_string(count);
                for(char ch: cnt)
                {
                    chars[ansindex++] = ch;
                }
            }
            //moving to new/different character
            i=j;
        }
        return ansindex;
    }
};