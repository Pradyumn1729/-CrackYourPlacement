class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0]; 
        int fast = arr[0]; 

        slow = arr[slow];
        fast = arr[arr[fast]];

        while(fast != slow ){
            slow = arr[slow];
            fast = arr[arr[fast]];
        }

        int p = arr[0];
        while(p != slow){
            slow= arr[slow];
            p = arr[p];
        }
        return p;
    }
};