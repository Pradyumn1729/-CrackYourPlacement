class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int i=0;
        int count = 1;
        for(int j=0; j<n; j++){
            if(i==j){
                continue;
            }
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                count++;
                i++;
            }
        }
        return count;
    }
};

