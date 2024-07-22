int maxLen(vector<int>& arr, int n) {
        unordered_map<int, int>mp;
        
        vector<int>prefix(n);
        
        prefix[0] = arr[0];
        
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        
        int len = 0;

        for(int i=0; i<n; i++){
            
            if(prefix[i] == 0){
                len = i + 1;
            }
            
            if(mp.find(prefix[i]) != mp.end()){
                len = max(len, i - mp[prefix[i]]);
            }
            if(mp.find(prefix[i]) == mp.end()){
                mp[prefix[i]] = i;
            }
            
        }
        
        return len;
    }