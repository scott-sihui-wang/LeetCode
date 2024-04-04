class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int len=nums.size();
        if(len<3)return true;
        int i=1;
        while(i<len && nums[i]-nums[0]==0){
            i++;
        }
        if(i==len){
            return true;
        }
        else{
            int benchmark=nums[i]-nums[0];
            if(benchmark>0){
                benchmark=1;
            }
            else if(benchmark<0){
                benchmark=-1;
            }
            for(int j=i+1;j<len;j++){
                if(nums[j]-nums[j-1]>0 && benchmark==-1){
                    return false;
                }
                else if(nums[j]-nums[j-1]<0 && benchmark==1){
                    return false;
                }
            }
            return true;
        }
    }
};