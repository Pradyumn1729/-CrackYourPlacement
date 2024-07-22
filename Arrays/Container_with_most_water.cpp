class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i=0, j=n-1;
        int area = (j-i) * min(arr[i], arr[j]);
        while(i < j){
            
            if(arr[i] <= arr[j])
                i++;
            else
                j--;
            
            int modified = min(arr[i], arr[j]) * (j - i);
            
            area = max(area, modified);

        }

        return area;
    }
};