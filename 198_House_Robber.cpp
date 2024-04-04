class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==1){
            return nums[0];
        }
        else if(len==2){
            return max(nums[0],nums[1]);
        }
        else{
            int reward[len+1];
            reward[0]=0;
            reward[1]=nums[0];
            reward[2]=max(nums[0],nums[1]);
            for(int i=3;i<len+1;i++){
                reward[i]=max(nums[i-1]+reward[i-2],nums[i-2]+reward[i-3]);
            }
            return reward[len];
        }
    }
};