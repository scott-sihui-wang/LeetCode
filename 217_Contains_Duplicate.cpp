class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>dict;
        unordered_map<int,int>::iterator iter;
        for(int i=0;i<nums.size();i++){
            iter=dict.find(nums[i]);
            if(iter==dict.end()){
                dict[nums[i]]=1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};