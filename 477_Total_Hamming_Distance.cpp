class Solution {
public:
    bool ended(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                return false;
            }
        }
        return true;
    }
    int totalHammingDistance(vector<int>& nums) {
        int len=nums.size();
        int bits[len];
        int sum=0;
        while(ended(nums)==false){
            int cnt=0;
            for(int i=0;i<len;i++){
                bits[i]=nums[i]%2;
                nums[i]=nums[i]/2;
                cnt+=bits[i];
            }
            sum+=(len-cnt)*cnt;
        }
        return sum;
    }
};