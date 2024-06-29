class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int i=0;
        while(i<nums.size() && nums[i]==1){
            i++;
        }
        while(i<nums.size()){
            if(i==0 || nums[i]!=nums[i-1]){
                ans++;
            }
            i++;
        }
        return ans;
    }
};