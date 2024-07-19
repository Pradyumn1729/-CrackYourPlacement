    class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // priority_queue<p, vector<p>, greater<p>>pq;

        vector<int>ans;
        int n = nums.size();
        unordered_map<int, int>mp;  

        for(auto &it : nums){
            mp[it]++;
        }

       vector<vector<int>>arr(n+1);

       for(auto &it : mp){
            arr[it.second].push_back(it.first);
       }

        for(int i=n; i>=0; i--){
            if(arr[i].size() == 0){
                continue;
            }

            while(arr[i].size() > 0 && k > 0){
                ans.push_back(arr[i].back());
                arr[i].pop_back();
                k--;
            }
        }

        return ans;
    }
};