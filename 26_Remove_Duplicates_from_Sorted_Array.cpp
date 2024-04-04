class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> sol;
        int len=nums.size();
        int idx=0;
        int unique=0;
        while(idx<len){
            int cur=nums[idx++];
            unique++;
            sol.push_back(cur);
            while(idx<len && nums[idx]==cur){
                idx++;
            }
        }
        nums=sol;
        return unique;
    }
};