class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(),str.end());
        for(auto vec: str)
            cout<<vec<<" ";

        string ans ="";
        int n = str.size();
        string first = str[0];   
        string last = str[n-1];

        for(int i=0;i<min(first.size() , last.size());i++){
            if(first[i]==last[i])
                ans+=first[i];
            else
                break;    
        }
        return ans;   
    }
};