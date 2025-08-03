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




    // string removeKdigits(string num, int k) {
    //   string ans = "";
    //   for(auto c: num){
    //       while(ans.size() && c < ans.back() && k) { ans.pop_back(); k--; }
    //       if(ans.size() + (c - '0')) ans.push_back(c);
    //   }
    //   while(k-- && ans.size()) ans.pop_back();
    //   return ans.size()?ans: "0";
    // }





    // string removeKdigits(string num, int k) {
    //     stack<char> st;

    //     // Loop through each digit in the input string
    //     for (char ch : num) {
    //         // While the stack is not empty, we have removals left (k > 0),
    //         // and the top of the stack is greater than the current digit,
    //         // we pop the top of the stack.
    //         while (!st.empty() && k > 0 && st.top() > ch) {
    //             st.pop();
    //             k--;
    //         }

    //         // Handle the case of leading zeros. We don't push a '0' if the
    //         // stack is currently empty, unless it's the only digit left.
    //         if (st.empty() && ch == '0') {
    //             continue;
    //         }

    //         st.push(ch);
    //     }

    //     // If there are still removals left (k > 0), it means the remaining
    //     // digits in the stack are in non-decreasing order. We should remove
    //     // the last k digits to make the number smallest.
    //     while (!st.empty() && k > 0) {
    //         st.pop();
    //         k--;
    //     }

    //     // If the stack is empty after all removals, it means all digits
    //     // were removed, so the result is "0".
    //     if (st.empty()) {
    //         return "0";
    //     }

    //     // Build the result string from the stack.
    //     // The stack contains the digits in reverse order, so we build the
    //     // string by prepending characters.
    //     string ans = "";
    //     while (!st.empty()) {
    //         ans += st.top();
    //         st.pop();
    //     }

    //     // The string is built in reverse, so we need to reverse it.
    //     reverse(ans.begin(), ans.end());

    //     return ans;



string removeKdigits(string num, int k) {
        string st;
        int n = num.length();
        if(k == n) return "0";

        for(int i=0; i<n; i++) {
            
            //remove bigger digits
            while( !st.empty() && k && st.back() > num[i] ) 
            {
                
                st.pop_back();
                k--;
            }

            //put anything 0 or non zero if stack is not empty
            //because it will not effect answer
            if(!st.empty())
            {
                st.push_back(num[i]);
            } 
            
            //stack is empty
            else 
            { 
                //if current digit is 0 we not take into stack
                //beacsue if stack is empty and if we push 0 
                //the answer will have trailing zero at first
                
                //only push non zero beacuse trailing zero not allowed
                if(num[i] != '0') {
                    st.push_back(num[i]);
                }
            }
        }
        
        //the remaining dgit removed from end to get smaller number
        while(k && !st.empty()) {
            st.pop_back();
            k--;
        }
        
        return st.empty() ? "0" : st;
    }

    
};