class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                cnt++;
                if(cnt==1){
                    if(!((i==0 || nums[i-1]<=nums[i+1])||(i+1==n-1 || nums[i]<=nums[i+2]))){
                        return false;
                    }
                }
                else if(cnt>1){
                    return false;
                }
            }
        }
        return cnt<2;
    }
};