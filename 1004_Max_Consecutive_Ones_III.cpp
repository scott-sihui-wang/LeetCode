class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len=nums.size();
        if(len<=k)return len;
        int idx_left=0,idx_right=0;
        int cnt_zero=0;
        int max_ones=k;
        while(idx_right<len){
            idx_right++;
            if(nums[idx_right-1]==0){
                cnt_zero++;
                if(cnt_zero>k){
                    max_ones=max(max_ones,idx_right-idx_left-1);
                }
                while(cnt_zero>k){
                    idx_left++;
                    if(nums[idx_left-1]==0){
                        cnt_zero--;
                    }
                }
            }
        }
        if(idx_left<=len){
            max_ones=max(max_ones,idx_right-idx_left);
        }
        return max_ones;
    }
};