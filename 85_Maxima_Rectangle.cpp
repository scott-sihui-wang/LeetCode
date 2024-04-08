class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> prefix_sum(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix_sum[i][j]=(matrix[i-1][j-1]=='1'?1:0)+prefix_sum[i-1][j]+prefix_sum[i][j-1]-prefix_sum[i-1][j-1];
            }
        }
        int ans=0;
        for(int i1=0;i1<m;i1++){
            for(int j1=0;j1<n;j1++){
                for(int i2=i1;i2<m;i2++){
                    if(matrix[i2][j1]!='1'){
                        break;
                    }
                    else{
                        ans=max(ans,i2-i1+1);
                        int begin=j1;
                        int end=n-1;
                        while(begin<=end){
                            int mid=(begin+end)/2;
                            int sum=prefix_sum[i2+1][mid+1]-prefix_sum[i2+1][j1]-prefix_sum[i1][mid+1]+prefix_sum[i1][j1];
                            int area=(i2-i1+1)*(mid-j1+1);
                            if(sum==area){
                                ans=max(ans,area);
                                begin=mid+1;
                            }
                            else{
                                end=mid-1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};