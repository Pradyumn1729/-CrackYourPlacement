class Solution {
public:
    vector<vector<int>>ans;

    void solve(int target, vector<int>& arr, int i){
        int n = arr.size();
        int j = n - 1;
        while(i < j) {
            if(arr[i] + arr[j] > target){
                j--;
            }
            else if (arr[i] + arr[j] < target){
                i++;
            }
            else {
                ans.push_back({-target, arr[i], arr[j]});

                while(i<j && arr[i] == arr[i+1])    i++;
                
                while(i<j && arr[j] == arr[j-1])    j--;

                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        if(n < 3)
            return {};

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++){
            if(i && nums[i] == nums[i-1]){
                continue;
            }

            solve(-nums[i], nums, i+1);
        }

        return ans;
    }
};