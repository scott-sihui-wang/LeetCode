class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int len=nums.size();
        if(len==1)return 0;
        long long sum[len+1];
        sum[0]=0;
        for(int i=1;i<=nums.size();i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
        int min_avg=1e6;
        int min_idx;
        for(int i=0;i<len;i++){
            long long diff;
            if(i<len-1){
                diff=abs(sum[i+1]/(i+1)-(sum[len]-sum[i+1])/(len-i-1));
            }
            else{
                diff=abs(sum[len]/len);
            }
            if(diff<min_avg){
                min_avg=diff;
                min_idx=i;
            }
        }
        
        return min_idx;
    }
};