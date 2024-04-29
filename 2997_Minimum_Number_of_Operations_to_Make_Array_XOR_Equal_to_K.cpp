class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res=res^nums[i];
        }
        res=res^k;
        int ans=0;
        while(res>0){
            ans+=res%2;
            res=res/2;
        }
        return ans;
    }
};