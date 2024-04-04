class Solution {
public:
    int jump(vector<int>& nums) {
        int len=nums.size();
        int sol[len];
        for(int i=0;i<len-1;i++){
            sol[i]=10001;
        }
        sol[len-1]=0;
        for(int i=len-2;i>=0;i--){
            for(int j=i+1;j<=min(i+nums[i],len-1);j++){
                sol[i]=min(sol[i],1+sol[j]);
            }
        }
        return sol[0];
    }
};