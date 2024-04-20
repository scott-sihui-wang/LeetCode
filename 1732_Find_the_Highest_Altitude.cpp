class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sz=gain.size();
        int ht[sz+1];
        ht[0]=0;
        int ans=0;
        for(int i=0;i<sz;i++){
            ht[i+1]=ht[i]+gain[i];
            ans=max(ans,ht[i+1]);
        }
        return ans;
    }
};