class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int len=nums.size();
        if(len==1)return nums[0];
        if(len==2)return max(max(nums[0],nums[1]),nums[0]+nums[1]);
        int sum=0;
        int M[len],m[len];
        int max_so_far=INT_MIN;
        int min_so_far=INT_MAX;
        for(int i=0;i<len;i++){
            sum+=nums[i];
            if(i==0){
                M[i]=nums[i];
                max_so_far=max(max_so_far,M[i]);
            }
            else if(i==1){
                M[i]=nums[i]+(M[i-1]>0?M[i-1]:0);
                max_so_far=max(max_so_far,M[i]);
                m[i]=nums[i];
                min_so_far=min(min_so_far,m[i]);
            }
            else if(i>1 && i<len-1){
                M[i]=nums[i]+(M[i-1]>0?M[i-1]:0);
                max_so_far=max(max_so_far,M[i]);
                m[i]=nums[i]+(m[i-1]<0?m[i-1]:0);
                min_so_far=min(min_so_far,m[i]);
            }
            else{
                M[i]=nums[i]+(M[i-1]>0?M[i-1]:0);
                max_so_far=max(max_so_far,M[i]);
            }
        }
        return max(max_so_far,sum-min_so_far);
    }
};