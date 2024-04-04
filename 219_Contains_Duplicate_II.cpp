class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int> >dict;
        unordered_map<int,vector<int> >::iterator iter;
        for(int i=0;i<nums.size();i++){
            iter=dict.find(nums[i]);
            if(iter==dict.end()){
                dict[nums[i]]=vector<int>(1,i);
            }
            else{
                int last=iter->second.size()-1;
                if(i-iter->second[last]<=k){
                    return true;
                }
                iter->second.push_back(i);
            }
        }
        return false;
    }
};