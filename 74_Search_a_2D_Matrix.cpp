class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_len=matrix[0].size();
        int col_len=matrix.size();
        int begin=0;
        int end=col_len*row_len-1;
        int mid;
        while(begin<=end){
            mid=(begin+end)/2;
            if(target==matrix[mid/row_len][mid%row_len]){
                return true;
            }
            else if(target<matrix[mid/row_len][mid%row_len]){
                end=mid-1;
            }
            else if(target>matrix[mid/row_len][mid%row_len]){
                begin=mid+1;
            }
        }
        return false;
    }
};