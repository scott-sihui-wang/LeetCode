class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>sol;
        unordered_map<int,int> dict;
        unordered_map<int,int>::iterator iter;
        int len=nums.size();
        for(int i=0;i<len;i++){
            iter=dict.find(target-nums[i]);
            if(iter!=dict.end()){
                sol.push_back(i);
                sol.push_back(iter->second);
                break;
            }
            else{
                dict[nums[i]]=i;
            }
        }
        return sol;
    }
};