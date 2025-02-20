class Solution {
    public boolean isUgly(int n) {
        if (n <= 0) {
            return false;  // Negative numbers and zero are not ugly numbers
        }
        
        // Divide the number by 2, 3, and 5 as long as possible
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        
        // If the number becomes 1, it only had 2, 3, or 5 as prime factors
        return n == 1;
    }
}