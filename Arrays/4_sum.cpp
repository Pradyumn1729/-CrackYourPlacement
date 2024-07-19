class Solution {
public:
    vector<vector<int>>result;
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        if(n<4)
            return {};
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            
            if(i>0 && arr[i]==arr[i-1]) continue;
            
            for(int j=i+1;j<n;j++){
                   if(j>i+1 && arr[j]==arr[j-1]) continue;
                   
                   int li=j+1;
                   int ri=n-1;
                  
                   while(li<ri){
                    long long sum=arr[i];
                    
                    sum+=arr[j];
                    sum+=arr[li];
                    sum+=arr[ri];

                    if(sum==target){
                        while(li<ri && arr[li]==arr[li+1]) li++;
                        while(li<ri && arr[ri]==arr[ri-1]) ri--;
                        vector<int>temp={arr[i],arr[j],arr[li],arr[ri]};
                        result.push_back(temp);
                        li++;
                        ri--;
                    }else if(sum<target){
                        li++;
                    }else{
                        ri--;
                    }
                }
                
            }
        }
        return result;
    }
};