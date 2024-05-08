class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int LIS_len[n],LIS_cnt[n];
        int max_len=1,max_cnt=1;
        LIS_len[0]=1;
        LIS_cnt[0]=1;
        for(int i=1;i<n;i++){
            LIS_len[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    LIS_len[i]=max(LIS_len[i],LIS_len[j]+1);
                }
            }
            max_len=max(max_len,LIS_len[i]);
            if(LIS_len[i]==1){
                LIS_cnt[i]=1;
            }
            else{
                LIS_cnt[i]=0;
                for(int j=0;j<i;j++){
                    if(nums[j]<nums[i] && LIS_len[j]+1==LIS_len[i]){
                        LIS_cnt[i]+=LIS_cnt[j];
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(LIS_len[i]==max_len){
                ans+=LIS_cnt[i];
            }
        }
        return ans;
    }
};