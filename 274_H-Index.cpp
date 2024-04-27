class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<>());
        int i=0;
        int ans=0;
        while(i<citations.size() && citations[i]>i+1){
            ans=max(ans,min(citations[i],i+1));
            i++;
        }
        if(i<citations.size()){
            ans=max(ans,min(citations[i],i+1));
        }
        return ans;
    }
};