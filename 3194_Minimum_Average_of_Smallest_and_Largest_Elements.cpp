class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        double ans=DBL_MAX;
        for(int i=0;i<nums.size()/2;i++){
            double avg=(nums[i]+nums[nums.size()-1-i])*1.0/2;
            ans=min(ans,avg);
        }
        return ans;
    }
};