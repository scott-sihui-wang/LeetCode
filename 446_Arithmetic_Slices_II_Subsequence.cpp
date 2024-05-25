class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<map<long,int>>dp(n);
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long diff=(long)nums[i]-(long)nums[j];
                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff]+=1+dp[j][diff];
                    ans+=dp[j][diff];
                }
                else{
                    dp[i][diff]+=1;
                }
            }
        }
        return ans;
    }
};