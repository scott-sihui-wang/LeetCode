class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int len=nums.size();
        vector<int>sol;
        if(len==0)return sol;
        int freq[1000];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                freq[nums[i][j]-1]=min(freq[nums[i][j]-1]+1,i+1);
            }
        }
        for(int i=0;i<1000;i++){
            if(freq[i]==nums.size()){
                sol.push_back(i+1);
            }
        }
        return sol;
    }
};