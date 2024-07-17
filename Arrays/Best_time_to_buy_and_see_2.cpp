class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=1; i<n; i++){
            int profit = arr[i] - arr[i-1];
            if(arr[i] > arr[i-1])
                ans += profit; 
        }

        return ans;
    }
};