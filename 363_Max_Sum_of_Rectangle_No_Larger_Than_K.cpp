class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int tar) {
        int m=matrix.size(),n=matrix[0].size();
        int sum[m+1][n];
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=m;i++){
            for(int j=0;j<n;j++){
                if(i==1){
                    sum[i][j]=matrix[i-1][j];
                }
                else{
                    sum[i][j]=matrix[i-1][j]+sum[i-1][j];
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m+1;j++){
                for(int p=0;p<n;p++){
                    int val=0;
                    for(int q=p;q<n;q++){
                        val+=sum[j][q]-sum[i][q];
                        if(val<tar){
                            ans=max(ans,val);
                        }
                        else if(val==tar){
                            return tar;
                        }
                    }
                }
            }
        }
        return ans;
    }
};