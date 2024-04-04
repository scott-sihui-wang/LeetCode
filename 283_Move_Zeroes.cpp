class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int len=nums.size();
        int cnt=0;
        while(i<len-cnt){
            while(i<len && nums[i]!=0){
                ++i;
            }
            if(i<len){
                cnt++;
                for(int j=i;j<len-cnt;j++){
                    int tmp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=tmp;
                }
            }
        }
    }
};