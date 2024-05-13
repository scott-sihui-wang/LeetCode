class Solution {
public:
    void flipRow(int row,vector<vector<int>>& grid){
        int n=grid[row].size();
        for(int i=0;i<n;i++){
            if(grid[row][i]==0){
                grid[row][i]=1;
            }
            else{
                grid[row][i]=0;
            }
        }
    }
    void flipCol(int col,vector<vector<int>>& grid){
        int n=grid.size();
        for(int i=0;i<n;i++){
            if(grid[i][col]==0){
                grid[i][col]=1;
            }
            else{
                grid[i][col]=0;
            }
        }
    }
    int cntCol(int col,vector<vector<int>>& grid){
        int ans=0;
        for(int i=0;i<grid.size();i++){
            if(grid[i][col]==1){
                ans++;
            }
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                flipRow(i,grid);
            }
        }
        for(int i=1;i<n;i++){
            int cnt=cntCol(i,grid);
            if(cnt<m-cnt){
                flipCol(i,grid);
            }
        }
        int ans=0;
        for(int i=0;i<grid[0].size();i++){
            ans+=(1<<(n-1-i))*cntCol(i,grid);
        }
        return ans;
    }
};