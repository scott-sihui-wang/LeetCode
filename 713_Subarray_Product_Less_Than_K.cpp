class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int prod;
        for(int i=0;i<nums.size();i++){
            prod=1;
            for(int j=0;j<nums.size()-i;j++){
                prod*=nums[i+j];
                if(prod<k){
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};