class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row=matrix.size();
        int col=matrix[0].size();
        int size=row*col;
        int* sol=new int[size];
        int cnt=0;
        int num_path=min((row+1)/2,(col+1)/2);
        for(int i=0;i<num_path;i++){
            for(int j=i;j<=col-1-i;j++){
                sol[cnt++]=matrix[i][j];
            }
            if(cnt==size)break;
            for(int j=i+1;j<=row-1-i;j++){
                sol[cnt++]=matrix[j][col-1-i];
            }
            if(cnt==size)break;
            for(int j=col-2-i;j>=i;j--){
                sol[cnt++]=matrix[row-1-i][j];
            }
            for(int j=row-2-i;j>=i+1;j--){
                sol[cnt++]=matrix[j][i];
            }
        }
        for(int i=0;i<size;i++){
            result.push_back(sol[i]);
        }
        return result;
    }
};