class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)return 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int ans=0;
        int j=0;
        for(int i=0;i<g.size();i++){
            while(j<s.size() && s[j]<g[i]){
                j++;
            }
            if(j==s.size()){
                return ans;
            }
            else{
                ans++;
                j++;
            }
        }
        return ans;
    }
};