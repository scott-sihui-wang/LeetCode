class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len=nums.size();
        vector<int> sol(len,INT_MIN);
        for(int i=0;i<len;i++){
            for(int j=1;j<len;j++){
                int idx=(i+j)%len;
                if(nums[idx]>nums[i]){
                    sol[i]=nums[idx];
                    break;
                }
            }
            if(sol[i]==INT_MIN){
                sol[i]=-1;
            }
        }
        return sol;
    }
};