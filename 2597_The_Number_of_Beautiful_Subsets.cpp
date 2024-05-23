class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        map<int,map<int,int>>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]%k][nums[i]]++;
        }
        int ans=1;
        for(map<int,map<int,int>>::iterator iter=freq.begin();iter!=freq.end();iter++){
            int n=iter->second.size();
            vector<pair<int,int>>fq;
            for(auto it=iter->second.begin();it!=iter->second.end();it++){
                fq.push_back({it->first,it->second});
            }
            int dp[n+1];
            dp[n]=1;
            for(int i=n-1;i>=0;i--){
                int skip=dp[i+1];
                int take=(1<<fq[i].second)-1;
                if(i+1<=n-1 && fq[i+1].first-fq[i].first==k){
                    take*=dp[i+2];
                }
                else{
                    take*=dp[i+1];
                }
                dp[i]=skip+take;
            }
            ans*=dp[0];
        }
        return ans-1;
    }
};