class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        if(freq.size()<=1){
            return 0;
        }
        map<int,int>::iterator iter=freq.begin();
        iter++;
        int ans=0;
        for(;iter!=freq.end();iter++){
            int v1=iter->first;
            iter--;
            int v2=iter->first;
            iter++;
            if(v1-v2==1){
                ans=max(ans,freq[v1]+freq[v2]);
            }
        }
        return ans;
    }
};