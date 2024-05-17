class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int val=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            val+=i*nums[i];
            sum+=nums[i];
        }
        int ans=val;
        for(int i=nums.size()-1;i>=1;i--){
            int diff=sum-nums.size()*nums[i];
            val+=diff;
            ans=max(ans,val);
        }
        return ans;
    }
};