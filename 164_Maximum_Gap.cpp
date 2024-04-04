class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int sz=nums.size();
        vector<int> b[sz];
        int m=INT_MAX,M=INT_MIN;
        for(int i=0;i<sz;i++){
            m=min(m,nums[i]);
            M=max(M,nums[i]);
        }
        for(int i=0;i<sz;i++){
            b[(nums[i]-m)/((M-m+1)/sz+1)].push_back(nums[i]);
        }
        for(int i=0;i<sz;i++){
            if(b[i].empty()==false){
                sort(b[i].begin(),b[i].end());
            }
        }
        int idx=0;
        int ans=0;
        for(int i=0;i<sz;i++){
            for(int j=0;j<b[i].size();j++){
                nums[idx]=b[i][j];
                if(idx!=0) ans=max(ans,nums[idx]-nums[idx-1]);
                idx++;
            }
        }
        return ans;
    }
};