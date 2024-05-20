class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0][0],M=matrix[n-1][n-1];
        while(m<=M){
            int mid=(m+M)/2;
            if(count(matrix,mid)<k){
                m=mid+1;
            }
            else{
                M=mid-1;
            }
        }
        return m;
    }
    int count(vector<vector<int>>& matrix, int val){
        int n=matrix.size();
        int ans=0;
        int begin=0,end=n-1;
        for(int i=0;i<n;i++){
            while(begin<=end){
                int mid=(begin+end)/2;
                if(matrix[i][mid]<=val){
                    begin=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            ans+=begin;
            end=begin-1;
            begin=0;
        }
        return ans;
    }
};