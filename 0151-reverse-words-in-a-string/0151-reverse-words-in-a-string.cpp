// class Solution {
// public:
//     string reverseWords(string s) {
//         int left = 0;
//         int right = s.length() - 1;
//         string temp = "";
//         string ans = "";

//         while (left <= right) {
//             char ch = s[left];
//             if (ch != ' ') {
//                 temp += ch;

//             } else if (ch == ' ') {
//                 if (ans != "") {
//                     ans = temp + " " + ans;
//                 } else {
//                     ans = temp;
//                 }
//                 temp = "";
//             }
//             left++;
//         }
//         if (temp != "") {
//             if (ans != "")
//                 ans = temp + " " + ans;
//             else
//                 ans = temp;
//         }
//         return ans;
//     }
// };

// //      s+=" ";
// //     stack<string> st;
// //     int i;
// //     string str="";
// //     for(i=0;i<s.length();i++)
// //     {
// //         if(s[i]==' ')
// //         {
// //             st.push(str);
// //             str="";
// //         }
// //         else str+=s[i];
// //     }
// //     string ans="";
// //     while(st.size()!=1)
// //     {
// //         ans+=st.top()+" ";
// //         st.pop();
// //     }
// //     ans+=st.top();// The last word should'nt have a space after it

// //     return ans;

// // }

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        s.resize(r);
        return s;
    }
};
