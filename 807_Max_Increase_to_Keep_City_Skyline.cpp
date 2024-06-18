class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> r(m,INT_MIN),c(n,INT_MIN);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                r[i]=max(r[i],grid[i][j]);
                c[j]=max(c[j],grid[i][j]);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans+=min(r[i],c[j])-grid[i][j];
            }
        }
        return ans;
    }
};