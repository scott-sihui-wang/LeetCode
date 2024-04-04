class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len=nums.size();
        int cnt[len];
        memset(cnt,0,sizeof(cnt));
        vector<int>sol;
        for(int i=0;i<len;i++){
            cnt[nums[i]-1]++;
            if(cnt[nums[i]-1]==2){
                sol.push_back(nums[i]);
            }
        }
        for(int i=0;i<len;i++){
            if(cnt[i]==0){
                sol.push_back(i+1);
                return sol;
            }
        }
        return sol;
    }
};