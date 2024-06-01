class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size(),n=img[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=img[i][j];
                int cnt=1;
                for(int k=0;k<8;k++){
                    int i0=i+dir[k][0];
                    int j0=j+dir[k][1];
                    if(i0>=0 && i0<m && j0>=0 && j0<n){
                        cnt++;
                        sum+=img[i0][j0];
                    }
                }
                ans[i][j]=sum/cnt;
            }
        }
        return ans;
    }
};