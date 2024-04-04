class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int sol[m][n];
        sol[0][0]=abs(1-obstacleGrid[0][0]);
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==1){
                sol[i][0]=0;
            }
            else{
                sol[i][0]=sol[i-1][0];
            }
        }
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]==1){
                sol[0][i]=0;
            }
            else{
                sol[0][i]=sol[0][i-1];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    sol[i][j]=0;
                }
                else{
                    sol[i][j]=sol[i-1][j]+sol[i][j-1];
                }
            }
        }
        return sol[m-1][n-1];
    }
};