class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=n/2;
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans+=nums[nums.size()-1-i]-nums[i];
        }
        return ans;
    }
};