class Solution {
public:
    void solve(bool** available,int n,int cur,int& num_sol){
        int flip_x[4*n];
        int flip_y[4*n];
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
                    solve(available,n,cur+1,num_sol);
                    for(int k=0;k<top;k++){
                        available[flip_x[k]][flip_y[k]]=true;
                    }
                }
                else if(cur==n){
                    num_sol++;
                }
            }
        }
    }
    int totalNQueens(int n) {
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
        int num_sol=0;
        solve(available,n,1,num_sol);
        return num_sol;
    }
};