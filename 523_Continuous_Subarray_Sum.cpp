class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2)return false;
        unordered_map<int,vector<int>>MOD;
        vector<int>sums;
        int sum=0;
        MOD[sum%k].push_back(0);
        sums.push_back(0);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sums.push_back(sum);
            if(MOD.find(sum%k)!=MOD.end()){
                if(i-MOD[sum%k][0]>=1){
                    return true;
                }
                MOD[sum%k].push_back(i+1);
            }
            else{
                MOD[sum%k].push_back(i+1);
            }
        }
        return false;
    }
};