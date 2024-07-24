class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.size();
        int i = 0;
     
        while(i < m){
            if(i+n <= m){
                string temp = haystack.substr(i, n);
                if(temp == needle){
                    return i;
                }
            }
            i++;
        }

        return -1;
    }
};