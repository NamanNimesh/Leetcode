class Solution {
public:
    string convert(string s, int numRows) {
          int n = s.size();

            if (n == 1 || numRows==1) {
                return s;
            }

            int p = 2 * numRows - 2; //pattern period

            string st(n,' ');
            int index=0;

            for (int i = 0; i < numRows; i++) {
                int curr = i;
                if (i == 0 || i == numRows - 1) {
                    while (curr < n) {
                        st[index]= s[curr];
                        index++;
                        curr += p;
                    }
                }
                else {
                    int it = 2*(numRows-i-1);
                    while (curr < n) {
                        st[index]= s[curr];
                        index++;
                        if (curr+it < n) {
                            st [index]= s[curr+it];
                            index++;

                        }
                        curr += p;

                    }
                }
            }
            return st;


    

    }
};