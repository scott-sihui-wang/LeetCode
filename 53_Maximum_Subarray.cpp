class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        int sum[len+1];
        for(int i=0;i<len+1;i++){
            if(i==0){
                sum[i]=0;
            }
            else{
                sum[i]=sum[i-1]+nums[i-1];
            }
        }
        int val[len];
        int max_val=sum[len];
        for(int i=len-1;i>=0;i--){
            if(sum[i+1]>max_val){
                max_val=sum[i+1];
            }
            val[i]=max_val-sum[i];
        }
        int sol=INT_MIN;
        for(int i=0;i<len;i++){
            if(val[i]>sol){
                sol=val[i];
            }
        }
        return sol;
    }
};