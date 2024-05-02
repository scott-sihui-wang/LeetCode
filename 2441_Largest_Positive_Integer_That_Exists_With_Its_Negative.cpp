class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>elems;
        for(int i=0;i<nums.size();i++){
            if(elems.find(nums[i])==elems.end()){
                elems.insert(nums[i]);
            }
        }
        sort(nums.begin(),nums.end());
        int idx=nums.size()-1;
        while(idx>=0 && nums[idx]>0){
            if(elems.find((-1)*nums[idx])!=elems.end()){
                return nums[idx];
            }
            idx--;
        }
        return -1;
    }
};