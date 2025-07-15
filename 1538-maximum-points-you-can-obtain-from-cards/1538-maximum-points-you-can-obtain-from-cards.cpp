class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0;
        for(int i = 0; i<k;i++){
            leftSum = leftSum + cardPoints[i];

        }  
        int maxSum = leftSum;
        int rightSum = 0, rightIndex = cardPoints.size()-1;
        for(int i = k-1; i >= 0;i--){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;

            maxSum = max(maxSum,leftSum+rightSum);
        }
        return maxSum;
    }
};