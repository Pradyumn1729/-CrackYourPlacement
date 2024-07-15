class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int cand = nums[0];
        int n = nums.size();
        
        for(int i=1; i<n; i++){
            if(!count){
                cand  = nums[i];
                count = 1;
            }else if(nums[i] == cand){
                count++;
            }else{
                count--;
            }
        }

        return cand;
    }
};

