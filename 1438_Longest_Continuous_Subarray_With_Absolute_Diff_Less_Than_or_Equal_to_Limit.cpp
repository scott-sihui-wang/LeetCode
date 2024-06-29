class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left=0,right=0;
        multiset<int>s;
        int ans=INT_MIN;
        while(right<nums.size()){
            while(right<nums.size() && (s.empty() || *s.rbegin()-*s.begin()<=limit)){
                s.insert(nums[right]);
                right++;
            }
            if(*s.rbegin()-*s.begin()>limit){
                ans=max(ans,right-left-1);
            }
            else{
                ans=max(ans,right-left);
            }
            while(left<nums.size() && *s.rbegin()-*s.begin()>limit){
                s.erase(s.find(nums[left]));
                left++;
            }
        }
        return ans;
    }
};