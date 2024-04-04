class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        unordered_map<int,int>::iterator iter;
        int left_ptr=0,right_ptr=0;
        int len=nums.size();
        int ans=0;
        while(right_ptr<len){
            right_ptr++;
            iter=freq.find(nums[right_ptr-1]);
            if(iter!=freq.end()){
                freq[nums[right_ptr-1]]++;
            }
            else{
                freq[nums[right_ptr-1]]=1;
            }
            if(freq[nums[right_ptr-1]]>k){
                ans=max(ans,right_ptr-left_ptr-1);
            }
            while(freq[nums[right_ptr-1]]>k){
                left_ptr++;
                freq[nums[left_ptr-1]]--;
            }
        }
        ans=max(ans,right_ptr-left_ptr);
        return ans;
    }
};