class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> sol;
        int len=nums.size();
        int k=0;
        for(int i=0;i<len;i++){
            if(nums[i]!=val){
                sol.push_back(nums[i]);
                k++;
            }
        }
        nums=sol;
        return k;
    }
};