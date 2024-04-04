class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>dict;
        unordered_map<int,int>::iterator iter;
        int len=nums.size();
        for(int i=0;i<len;i++){
            iter=dict.find(nums[i]);
            if(iter==dict.end()){
                dict[nums[i]]=1;
            }
            else{
                iter->second=iter->second+1;
            }
        }
        vector<int>sol;
        for(iter=dict.begin();iter!=dict.end();iter++){
            if(iter->second>len/3){
                sol.push_back(iter->first);
            }
        }
        return sol;
    }
};