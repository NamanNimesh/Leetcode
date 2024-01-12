class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int prod = 1;
        int sum = 0;
        while(n!=0)
        {
            int r = n%10;
             prod = prod*r;
             sum = sum+r;
             n=n/10;
        }
        int result = prod - sum;
        

        return result;
        
    }
};