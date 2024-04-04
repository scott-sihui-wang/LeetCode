class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> >sol;
        for(int i=0;i<n;i++){
            vector<int> sol_row(n);
            sol.push_back(sol_row);
        }
        int num_path=n/2;
        int extra=n%2;
        int cnt=1;
        for(int i=0;i<num_path;i++){
            for(int j=i;j<=n-1-i;j++){
                sol[i][j]=cnt++;
            }
            for(int j=i+1;j<=n-1-i;j++){
                sol[j][n-1-i]=cnt++;
            }
            for(int j=n-2-i;j>=i;j--){
                sol[n-1-i][j]=cnt++;
            }
            for(int j=n-2-i;j>=i+1;j--){
                sol[j][i]=cnt++;
            }
        }
        if(extra==1){
            sol[n/2][n/2]=cnt++;
        }
        return sol;
    }
};