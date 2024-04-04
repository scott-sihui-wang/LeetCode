class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len=nums.size();
        if(target<nums[0]){
            return 0;
        }
        for(int i=0;i<len;i++){
            if(target==nums[i]){
                return i;
            }
            else if(i<len-1 && target>nums[i] && target<nums[i+1]){
                return i+1;
            }
        }
        return len;
    }
};