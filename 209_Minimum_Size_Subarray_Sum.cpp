class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0;
        int len=nums.size();
        int min_sz=INT_MAX;
        int sum=0;
        while(right<len){
            while(right<len && sum<target){
                sum+=nums[right];
                right++;
            }
            if(sum>=target){
                while(left<right && sum>=target){
                    sum-=nums[left];
                    left++;
                }
                if(min_sz>right-left+1)min_sz=right-left+1;
            }
        }
        return min_sz==INT_MAX?0:min_sz;
    }
};