class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int val[500001]={};
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && nums[i]<=500001){
                val[nums[i]-1]=1;
            }
        }
        int i=0;
        for(;i<500001;i++){
            if(val[i]!=1){
                break;
            }
        }
        return i+1;
    }
};