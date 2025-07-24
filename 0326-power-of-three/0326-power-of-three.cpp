class Solution {
public:
    bool isPowerOfThree(int n) {
     // base case
       if(n==1)
       return true;
       if(n%3!=0 || n<=0)
       return false;
     // recursive function
       bool ans=false;
       ans= isPowerOfThree(n/3);
       return ans; 
    }
     // Hope it helps! Kindly Upvote.
};