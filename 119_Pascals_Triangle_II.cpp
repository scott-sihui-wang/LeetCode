class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int seq1[rowIndex+1];
        int seq2[rowIndex+1];
        int *src;
        int *dst=seq1;
        bool flag=true;
        seq1[0]=1;
        for(int i=1;i<=rowIndex;i++){
            flag=!flag;
            if(flag){
                src=seq2;
                dst=seq1;
            }
            else{
                src=seq1;
                dst=seq2;
            }
            dst[0]=src[0];
            dst[i]=src[i-1];
            for(int j=1;j<i;j++){
                dst[j]=src[j-1]+src[j];
            }
        }
        vector<int> sol;
        for(int i=0;i<=rowIndex;i++){
            sol.push_back(dst[i]);
        }
        return sol;
    }
};