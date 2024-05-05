class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pf[nums.size()];
        pf[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pf[i]=nums[i]+pf[i-1];
        }
        int ans=0;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            if(pf[i]==k){
                ans++;
            }
            if(freq.find(pf[i]-k)!=freq.end()){
                ans+=freq[pf[i]-k];
            }
            freq[pf[i]]++;
        }
        return ans;
    }
};