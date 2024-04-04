class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        bool reach[len];
        reach[len-1]=true;
        for(int i=len-2;i>=0;i--){
            reach[i]=false;
            for(int j=i+1;j<=i+nums[i];j++){
                if(reach[j]){
                    reach[i]=true;
                    break;
                }
            }
        }
        return reach[0];
    }
};