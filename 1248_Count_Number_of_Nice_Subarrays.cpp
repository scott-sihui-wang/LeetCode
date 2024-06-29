class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left=0,right=0,cnt=0,res=0,ans=0;
        while(right<nums.size()){
            res=0;
            while(right<nums.size() && cnt<=k){
                if(nums[right]%2==1){
                    cnt++;
                }
                if(cnt==k){
                    res++;
                }
                else if(cnt>k){
                    break;
                }
                right++;
            }
            while(left<=right && (cnt>k || (cnt==k && right>=nums.size()))){
                if(nums[left]%2==1){
                    cnt--;
                }
                left++;
                ans+=res;
            }
            if(right<nums.size() && nums[right]%2==1){
                cnt--;
            }
        }
        return ans;
    }
};