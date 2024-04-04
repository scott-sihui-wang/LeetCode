class Solution {
public:
    void solve(int* p_x, int* p_y,bool** available,int n,int cur,vector<vector<string>>& sol){
        int flip_x[4*n-3];
        int flip_y[4*n-3];
        int top;
        for(int i=0;i<n;i++){
            top=0;
            if(available[cur-1][i]==true){
                if(cur<n){
                    available[cur-1][i]=false;
                    flip_x[top]=cur-1;
                    flip_y[top++]=i;
                    for(int k=0;k<n;k++){
                        if(available[k][i]==true){
                            available[k][i]=false;
                            flip_x[top]=k;
                            flip_y[top++]=i;
                        }
                        if(available[cur-1][k]==true){
                            available[cur-1][k]=false;
                            flip_x[top]=cur-1;
                            flip_y[top++]=k;
                        }
                        if(cur-1+k-i>=0 && cur-1+k-i<n && available[cur-1+k-i][k]==true){
                            available[cur-1+k-i][k]=false;
                            flip_x[top]=cur-1+k-i;
                            flip_y[top++]=k;
                        }
                        if(cur-1-k+i>=0 && cur-1-k+i<n && available[cur-1-k+i][k]==true){
                            available[cur-1-k+i][k]=false;
                            flip_x[top]=cur-1-k+i;
                            flip_y[top++]=k;
                        }
                    }
                    *(p_x+cur-1)=cur-1;
                    *(p_y+cur-1)=i;
                    solve(p_x,p_y,available,n,cur+1,sol);
                    for(int k=0;k<top;k++){
                        available[flip_x[k]][flip_y[k]]=true;
                    }
                }
                else if(cur==n){
                    *(p_x+cur-1)=cur-1;
                    *(p_y+cur-1)=i;
                    vector<string> sub_sol(n,string(n,'.'));
                    for(int k=0;k<n;k++){
                        sub_sol[p_x[k]][p_y[k]]='Q';
				    }
				    sol.push_back(sub_sol);
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int p_x[n];
        int p_y[n];
        bool** available;
        available =new bool*[n];
        for(int i=0;i<n;i++){
            available[i]=new bool[n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                available[i][j]=true;
            }
        }
        vector<vector<string> >sol;
        solve(p_x,p_y,available,n,1,sol);
        return sol;
    }
};