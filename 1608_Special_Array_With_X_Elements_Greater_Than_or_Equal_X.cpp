class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1]==0)return -1;
        int i=1;
        while(i<=nums.size() && nums[nums.size()-i]>=i){
            i++;
        }
        if(i<=nums.size() && nums[nums.size()-i]>=i-1){
            return -1;
        }
        return i-1;
    }
};