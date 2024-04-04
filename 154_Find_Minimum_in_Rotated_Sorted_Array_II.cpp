class Solution {
public:
    int findMin(vector<int>& nums) {
        int change=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                change=i+1;
                break;
            }
        }
        return nums[change];
    }
};