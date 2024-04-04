class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        int prefix[len-1],suffix[len-1];
        vector<int> ans;
        prefix[0]=nums[0];
        suffix[0]=nums[len-1];
        for(int i=1;i<len-1;i++){
            prefix[i]=prefix[i-1]*nums[i];
            suffix[i]=suffix[i-1]*nums[len-1-i];
        }
        for(int i=0;i<len;i++){
            int product_left=(i>0?prefix[i-1]:1);
            int product_right=(i<len-1?suffix[len-2-i]:1);
            ans.push_back(product_left*product_right);
        }
        return ans;
    }
};