class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix,int r1,int c1,int r2,int c2,int target){
        if(r2<r1 || c2<c1)return false;
        int begin=c1,end=c2;
        while(begin<=end){
            int mid=(begin+end)/2;
            if(matrix[r1][mid]==target){
                return true;
            }
            else if(matrix[r1][mid]<target){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        if(end==c1-1){
            return false;
        }
        else{
            return binarySearch(matrix,r1+1,c1,r2,end,target);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch(matrix,0,0,matrix.size()-1,matrix[0].size()-1,target);
    }
};