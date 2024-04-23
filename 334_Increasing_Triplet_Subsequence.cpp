class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min_so_far_1=INT_MAX,min_so_far_2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min_so_far_1){
                min_so_far_1=nums[i];
            }
            else if(nums[i]>min_so_far_1 && nums[i]<min_so_far_2){
                min_so_far_2=nums[i];
            }
            else if(nums[i]>min_so_far_2){
                return true;
            }
        }
        return false;
    }
};
