class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int MOD=1000000007;
        long long tab[nums.size()];
        tab[0]=1;
        for(int i=1;i<nums.size();i++){
            tab[i]=(tab[i-1]*2)%MOD;
        }
        int l=0,r=nums.size()-1;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans=(ans+tab[r-l])%MOD;
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};