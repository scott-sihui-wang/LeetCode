class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int len=mat.size();
        int sum=0;
        for(int i=0;i<len;i++){
            sum+=mat[i][i];
            sum+=mat[len-1-i][i];
        }
        if(len%2==1){
            sum-=mat[len/2][len/2];
        }
        return sum;
    }
};