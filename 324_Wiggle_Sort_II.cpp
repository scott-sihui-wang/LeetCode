class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> cpy(nums.size());
        for(int i=0;i<nums.size();i++){
            cpy[i]=nums[i];
        }
        sort(cpy.begin(),cpy.end());
        int j=nums.size()-1;
        for(int i=1;i<nums.size();i+=2){
            nums[i]=cpy[j--];
        }
        for(int i=0;i<nums.size();i+=2){
            nums[i]=cpy[j--];
        }
    }
};