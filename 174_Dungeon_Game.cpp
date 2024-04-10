class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        int HP[m][n];
        memset(HP,-1,sizeof(HP));
        HP[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);
        if(n>1){
            for(int i=n-2;i>=0;i--){
                HP[m-1][i]=max(1,HP[m-1][i+1]-dungeon[m-1][i]);
            }
        }
        if(m>1){
            for(int i=m-2;i>=0;i--){
                HP[i][n-1]=max(1,HP[i+1][n-1]-dungeon[i][n-1]);
            }
        }
        if(m>1 && n>1){
            for(int i=m-2;i>=0;i--){
                for(int j=n-2;j>=0;j--){
                    HP[i][j]=min(max(1,HP[i+1][j]-dungeon[i][j]),max(1,HP[i][j+1]-dungeon[i][j]));
                }
            }
        }
        return HP[0][0];
    }
};