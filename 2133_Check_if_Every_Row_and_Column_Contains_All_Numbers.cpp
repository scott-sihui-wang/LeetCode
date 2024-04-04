class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int len=matrix.size();
        bool flag=true;
        bool available[len];
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                available[j]=true;
            }
            for(int j=0;j<len;j++){
                int idx=matrix[i][j]-1;
                if(available[idx]==true){
                    available[idx]=false;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag==false){
                break;
            }
            for(int j=0;j<len;j++){
                available[j]=true;
            }
            for(int j=0;j<len;j++){
                int idx=matrix[j][i]-1;
                if(available[idx]==true){
                    available[idx]=false;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag==false){
                break;
            }
        }
        return flag;
    }
};