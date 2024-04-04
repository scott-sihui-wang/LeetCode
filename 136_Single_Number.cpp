class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val[60001]={};
        int len=nums.size();
        for(int i=0;i<len;i++){
            val[nums[i]+30000]++;
        }
        int i=0;
        for(;i<60001;i++){
            if(val[i]==1){
                break;
            }
        }
        return i-30000;
    }
};