class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>grid(n,vector<int>(n,1));
        for(int i=0;i<mines.size();i++){
            grid[mines[i][0]][mines[i][1]]=0;
        }
        int left[n][n],right[n][n],down[n][n],up[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                left[i][j]=grid[i][j]+(grid[i][j]==1&& j>0 ? left[i][j-1]: 0);
            }
            for(int j=n-1;j>=0;j--){
                right[i][j]=grid[i][j]+(grid[i][j]==1 && j<n-1 ? right[i][j+1] : 0);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                up[j][i]=grid[j][i]+(grid[j][i]==1 && j>0 ? up[j-1][i] : 0);
            }
            for(int j=n-1;j>=0;j--){
                down[j][i]=grid[j][i]+(grid[j][i]==1 && j<n-1 ? down[j+1][i] : 0);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,min(left[i][j],min(right[i][j],min(up[i][j],down[i][j]))));
            }
        }
        return ans;
    }
};