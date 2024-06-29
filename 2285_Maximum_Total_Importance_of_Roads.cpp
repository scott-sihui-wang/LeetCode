class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>deg(n,0);
        for(int i=0;i<roads.size();i++){
            deg[roads[i][0]]++;
            deg[roads[i][1]]++;
        }
        sort(deg.begin(),deg.end());
        long long m=1,ans=0;
        for(int i=0;i<deg.size();i++){
            ans+=m*deg[i];
            m++;
        }
        return ans;
    }
};