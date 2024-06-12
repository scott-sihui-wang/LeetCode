class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int row[m],col[n];
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(row[i]>=2 && col[j]>=2){
                        ans+=(row[i]-1)*(col[j]-1);
                    }
                }
            }
        }
        return ans;
    }
};