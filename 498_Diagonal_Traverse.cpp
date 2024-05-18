class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int>ans;
        bool x_first=true;
        for(int i=0;i<m+n-1;i++){
            if(x_first){
                for(int j=max(i-m+1,0);j<=min(i,n-1);j++){
                    ans.push_back(mat[i-j][j]);
                }
            }
            else{
                for(int j=max(i-n+1,0);j<=min(i,m-1);j++){
                    ans.push_back(mat[j][i-j]);
                }
            }
            x_first=!x_first;
        }
        return ans;
    }
};