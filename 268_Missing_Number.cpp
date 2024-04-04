class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len=nums.size();
        int val[10001]={};
        for(int i=0;i<len;i++){
            val[nums[i]]=1;
        }
        int i=0;
        for(;i<len+1;i++){
            if(val[i]!=1){
                break;
            }
        }
        return i;
    }
};