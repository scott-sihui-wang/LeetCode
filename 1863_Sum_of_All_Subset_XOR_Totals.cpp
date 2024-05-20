class Solution {
public:
    void solve(vector<int>& nums,int idx,int& sum,int prev){
        for(int i=idx;i<nums.size();i++){
            sum+=prev^nums[i];
            solve(nums,i+1,sum,prev^nums[i]);
        }
    }
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        solve(nums,0,ans,0);
        return ans;
    }
};