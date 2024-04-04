class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int freq[n];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<nums.size();i++){
            freq[nums[i]-1]++;
            if(freq[nums[i]-1]==2){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};