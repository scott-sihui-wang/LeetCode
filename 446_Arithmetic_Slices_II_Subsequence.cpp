class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        map<int,map<long long,int>>dp;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                dp[i][(long long)(nums[i])-(long long)(nums[j])]+=1+dp[j][(long long)(nums[i])-(long long)(nums[j])];
            }
        }
        int ans=0;
        for(auto iter1=dp.begin();iter1!=dp.end();iter1++){
            for(auto iter2=iter1->second.begin();iter2!=iter1->second.end();iter2++){
                ans+=iter2->second;
            }
        }
        int n=nums.size();
        ans-=n*(n-1)/2;
        return ans;
    }
};