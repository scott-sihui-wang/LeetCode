class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0,len=nums.size();
        vector<string> ans;
        while(i<len){
            string interval=to_string(nums[i]);
            int i_prev=i;
            while(i+1<len && nums[i+1]==nums[i]+1){
                i++;
            }
            if(i>i_prev){
                interval+="->";
                interval+=to_string(nums[i]);
                
            }
            ans.push_back(interval);
            i++;
        }
        return ans;
    }
};