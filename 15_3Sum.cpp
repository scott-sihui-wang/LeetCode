class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>>idx;
        for(int i=0;i<nums.size();i++){
            if(idx.find(nums[i])==idx.end()){
                idx[nums[i]]={i};
            }
            else{
                idx[nums[i]].push_back(i);
            }
        }
        int i=0;
        while(i<nums.size()-2 && nums[i]<=0){
            int j=i+1;
            while(j<nums.size()-1 && nums[i]+nums[j]<=0){
                if(idx.find(-nums[i]-nums[j])!=idx.end()){
                    for(int k=0;k<idx[-nums[i]-nums[j]].size();k++){
                        if(idx[-nums[i]-nums[j]][k]>j){
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[idx[-nums[i]-nums[j]][k]]);
                            ans.push_back(v);
                            break;
                        }
                    }
                }
                do{
                    ++j;
                }
                while(j<nums.size()-1 && nums[j-1]==nums[j]);
            }
            do{
                ++i;
            }
            while(i<nums.size()-2 && nums[i-1]==nums[i]);
        }
        return ans;
    }
};