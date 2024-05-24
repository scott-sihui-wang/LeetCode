class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)return 0;
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            int k=i+2;
            while(k<nums.size() && nums[k]-nums[k-1]==nums[i+1]-nums[i]){
                k++;
            }
            ans+=k-i-2;
        }
        return ans;
    }
};