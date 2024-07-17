//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& temp, vector<int>& arr, vector<bool>& used, int n) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            // Skip duplicates
            if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            temp.push_back(arr[i]);
            solve(temp, arr, used, n);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> uniquePerms(vector<int>& arr, int n) {
        sort(arr.begin(), arr.end()); // Sort the array to handle duplicates
        vector<int> temp;
        vector<bool> used(n, false);
        solve(temp, arr, used, n);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends