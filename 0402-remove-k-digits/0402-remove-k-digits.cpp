class Solution {
public:
    // string removeKdigits(string num, int k) {
    //     stack<char> st;
    //     for(int i = 0; i <num.size() ; i++){
    //         while(!st.empty() && k>0 && (st.top()-'0') > (num[i]-'0')){
    //             st.pop();
    //             k--;
    //         }
    //         st.push(num[i]);
    //     }
    //     while(k>0){
    //         st.pop();
    //         k--;
    //     }
    //     if(st.empty()){
    //         return "0";
    //     }
    //     string res = "";
    //     while(!st.empty()){
    //         res = res + st.top();
    //         st.pop();

    //     }
    //     while(res.size() != 0 && res.back() == '0'){
    //         res.pop_back();
    //     }
    //     reverse(res.begin(),res.end());
    //     if(res.empty()){
    //         return "0";
    //     }
    //     return res;
    // }

    string removeKdigits(string num, int k) {
      string ans = "";
      for(auto c: num){
          while(ans.size() && c < ans.back() && k) { ans.pop_back(); k--; }
          if(ans.size() + (c - '0')) ans.push_back(c);
      }
      while(k-- && ans.size()) ans.pop_back(); 
      return ans.size()?ans: "0";
  }
};