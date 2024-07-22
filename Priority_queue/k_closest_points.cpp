class Solution {
public:
    typedef pair<int, pair<int , int>> p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p>pq;

        for(auto vec : points){
            int x = vec[0];
            int y = vec[1];

            pq.push({(pow(x, 2) + pow(y, 2)), {vec[0], vec[1]}});
            
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>>ans;

        while(k--){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};