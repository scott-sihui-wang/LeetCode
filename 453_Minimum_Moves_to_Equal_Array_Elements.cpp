class Solution {
public:
    int minMoves(vector<int>& nums) {
        int num_min=INT_MAX,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            num_min=min(num_min,nums[i]);
        }
        return sum-nums.size()*num_min;
    }
};