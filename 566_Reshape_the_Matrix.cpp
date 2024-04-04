class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int r0=mat.size();
        int c0=mat[0].size();
        if(r0*c0==r*c){
            vector<vector<int> >sol(r,vector<int>(c));
            for(int i=0;i<r0;i++){
                for(int j=0;j<c0;j++){
                    sol[(i*c0+j)/c][(i*c0+j)%c]=mat[i][j];
                }
            }
            return sol;
        }
        else{
            return mat;
        }
    }
};