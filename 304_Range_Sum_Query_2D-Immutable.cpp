class NumMatrix {
public:
    int pf[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<=n;i++){
            pf[0][i]=0;
        }
        for(int i=0;i<=m;i++){
            pf[i][0]=0;
        }
        pf[1][1]=matrix[0][0];
        for(int i=1;i<n;i++){
            pf[1][i+1]=pf[1][i]+matrix[0][i];
        }
        for(int i=1;i<m;i++){
            pf[i+1][1]=pf[i][1]+matrix[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                pf[i+1][j+1]=pf[i+1][j]+pf[i][j+1]-pf[i][j]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pf[row2+1][col2+1]-pf[row2+1][col1]-pf[row1][col2+1]+pf[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */