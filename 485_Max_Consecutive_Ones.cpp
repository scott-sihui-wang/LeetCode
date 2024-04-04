class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len=nums.size();
        int i=0;
        int max_len=0;
        while(i<len){
            int start=i;
            while(i+1<len && nums[i]==nums[i+1]){
                i++;
            }
            if(nums[i]==1){
                max_len=max(max_len,i-start+1);
            }
            i++;
        }
        return max_len;
    }
};