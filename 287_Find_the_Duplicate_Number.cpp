class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int stat[100000];
        for(int i=0;i<100000;i++){
            stat[i]=0;
        }
        int len=nums.size();
        int i=0;
        for(;i<len;i++){
            stat[nums[i]-1]++;
            if(stat[nums[i]-1]==2){
                break;
            }
        }
        return nums[i];
    }
};