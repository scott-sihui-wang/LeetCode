class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        vector<int> sol(len);
        for(int i=0;i<len;i++){
            int idx=(i-k)%len;
            while(idx<0){
                idx=idx+len;
            }
            sol[i]=nums[idx];
        }
        nums=sol;
    }
};