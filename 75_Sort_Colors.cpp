class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nums_len=nums.size();
        int i=0;
        int red_end=-1;
        int blue_begin=nums_len;
        while(i<blue_begin){
            if(nums[i]==2){
                nums[i]=nums[--blue_begin];
                nums[blue_begin]=2;
            }
            else if(nums[i]==1){
                i++;
            }
            else if(nums[i]==0){
                nums[i]=nums[++red_end];
                nums[red_end]=0;
                if(i==red_end){
                    i++;
                }
            }
        }
    }
};