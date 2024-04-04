class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        else if(n==2){
            return max(nums[0],nums[1]);
        }
        else if(n==3){
            return max(max(nums[0],nums[1]),nums[2]);
        }
        else if(n==4){
            return max(nums[0]+nums[2],nums[1]+nums[3]);
        }
        else{
            int dp1[n-1];
            int dp2[n-2];
            dp1[0]=0;
            dp1[1]=nums[1];
            for(int i=2;i<n-1;i++){
                dp1[i]=max(nums[i]+dp1[i-2],nums[i-1]+dp1[max(i-3,0)]);
            }
            dp2[0]=0;
            dp2[1]=nums[2];
            for(int i=2;i<n-2;i++){
                dp2[i]=max(nums[i+1]+dp2[i-2],nums[i]+dp2[max(i-3,0)]);
            }
            return max(max(nums[n-1]+dp1[n-3],nums[0]+dp2[n-3]),dp1[n-2]);
        }
    }
};