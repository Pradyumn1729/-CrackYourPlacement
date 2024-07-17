class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int lSum=0, rSum=0, maxSum =0;

        for(int i=0; i<k; i++){
            lSum += arr[i];
        }

        maxSum = lSum;
        int rightInd = n-1;

        for(int i=k-1; i>=0; i--){
            lSum = lSum - arr[i];
            rSum = rSum + arr[rightInd];
            maxSum = max(maxSum, lSum + rSum);
            rightInd--;
        }

        return maxSum;
    }
};