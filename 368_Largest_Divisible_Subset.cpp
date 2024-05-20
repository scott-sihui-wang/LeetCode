class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int len[n],prev[n];
        for(int i=0;i<n;i++){
            len[i]=1;
            prev[i]=-1;
        }
        int max_len=1,max_idx=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0 && len[j]<len[i]+1){
                    len[j]=len[i]+1;
                    prev[j]=i;
                }
                if(len[j]>max_len){
                    max_len=len[j];
                    max_idx=j;
                }
            }
        }
        vector<int>ans;
        while(max_idx!=-1){
            ans.push_back(nums[max_idx]);
            max_idx=prev[max_idx];
        }
        return ans;
    }
};