class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int len=nums.size();
        long long sum[len];
        for(int i=0;i<len;i++){
            if(i==0){
                sum[i]=nums[i];
            }
            else{
                sum[i]=sum[i-1]+nums[i];
            }
        }
        int cnt=0;
        for(int i=0;i<len-1;i++){
            if(sum[i]*2>=sum[len-1]){
                cnt++;
            }
        }
        return cnt;
    }
};