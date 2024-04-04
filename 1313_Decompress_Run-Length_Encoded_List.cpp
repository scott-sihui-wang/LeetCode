class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>sol;
        int i=0;
        while(i<nums.size()){
            for(int j=0;j<nums[i];j++){
                sol.push_back(nums[i+1]);
            }
            i+=2;
        }
        return sol;
    }
};