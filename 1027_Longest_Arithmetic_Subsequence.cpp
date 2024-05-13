class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n;
        vector<unordered_map<int,int>>diff(n);
        int ans=2;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(diff[j].find(nums[i]-nums[j])==diff[j].end()){
                    if(diff[i].find(nums[i]-nums[j])==diff[i].end()){
                        diff[i][nums[i]-nums[j]]=2;
                    }
                    else{
                        diff[i][nums[i]-nums[j]]=max(2,diff[i][nums[i]-nums[j]]);
                    }
                    ans=max(ans,diff[i][nums[i]-nums[j]]);
                }
                else{
                    if(diff[i].find(nums[i]-nums[j])==diff[i].end()){
                        diff[i][nums[i]-nums[j]]=diff[j][nums[i]-nums[j]]+1;
                    }
                    else{
                        diff[i][nums[i]-nums[j]]=max(diff[j][nums[i]-nums[j]]+1,diff[i][nums[i]-nums[j]]);
                    }
                    ans=max(ans,diff[i][nums[i]-nums[j]]);
                }
            }
        }
        return ans;
    }
};