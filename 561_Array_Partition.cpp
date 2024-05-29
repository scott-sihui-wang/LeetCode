class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()){
            ans+=nums[i];
            i+=2;
        }
        return ans;
    }
};