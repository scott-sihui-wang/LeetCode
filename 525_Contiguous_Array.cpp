class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,vector<int>>idx;
        int cnt=0;
        idx[cnt].push_back(-1);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
            }
            else if(nums[i]==0){
                cnt--;
            }
            idx[cnt].push_back(i);
        }
        int ans=0;
        for(auto iter=idx.begin();iter!=idx.end();iter++){
            if(iter->second.size()>=2){
                ans=max(ans,iter->second[iter->second.size()-1]-iter->second[0]);
            }
        }
        return ans;
    }
};