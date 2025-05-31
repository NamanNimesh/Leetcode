class Solution {
public:
    double myPow(double x, int n) {
        //using binary expotentation
        double ans = 1.0;
        long long nn = n;
        //checking if the expotent is negative or not
        if(nn < 0){
           nn =  -1 * nn;
        }

        while(nn){
            if(nn % 2){
                ans = ans*x;
                nn = nn-1;
            }
            else{
                x = x * x;
                nn = nn/2;
            }
        }
        if(n < 0){
            ans = (double)(1.0)/(double)(ans);
        }
        return ans;
        
    }
};