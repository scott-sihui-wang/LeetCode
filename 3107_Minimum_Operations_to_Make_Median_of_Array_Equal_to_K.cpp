class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums[n/2]==k){
            return 0;
        }
        else if(nums[n/2]>k){
            long long ans=0;
            int i=n/2;
            while(i>=0 && nums[i]>k){
                ans+=(long long)nums[i]-(long long)k;
                i--;
            }
            return ans;
        }
        else{
            long long ans=0;
            int i=n/2;
            while(i<n && nums[i]<k){
                ans+=(long long)k-(long long)nums[i];
                i++;
            }
            return ans;
        }
    }
};