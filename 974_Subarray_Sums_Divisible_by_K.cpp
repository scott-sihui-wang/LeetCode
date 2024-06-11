class Solution {
public:
    int MOD(int n,int k){
        if(n>=0){
            return n%k;
        }
        else{
            return (n%k+k)%k;
        }
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt[k];
        memset(cnt,0,sizeof(cnt));
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            cnt[MOD(sum,k)]++;
        }
        int ans=cnt[0];
        for(int i=0;i<k;i++){
            if(cnt[i]>=2){
                ans+=cnt[i]*(cnt[i]-1)/2;
            }
        }
        return ans;
    }
};