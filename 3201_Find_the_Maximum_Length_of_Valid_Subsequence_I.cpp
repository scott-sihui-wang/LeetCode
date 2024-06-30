class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int cnt_odd=0,cnt_even=0,cnt_alt=0;
        int prev=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                cnt_even++;
            }
            else{
                cnt_odd++;
            }
            if(i==0){
                prev=i;
                cnt_alt++;
            }
            else{
                if(nums[i]%2!=nums[prev]%2){
                    prev=i;
                    cnt_alt++;
                }
            }
        }
        return max(cnt_alt,max(cnt_odd,cnt_even));
    }
};