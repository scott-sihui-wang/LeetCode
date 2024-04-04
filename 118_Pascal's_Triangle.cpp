class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> >sol;
        int seq1[numRows];
        int seq2[numRows];
        int* src;
        int* dst;
        bool flag=true;
        seq1[0]=1;
        vector<int> sub_sol;
        sub_sol.push_back(seq1[0]);
        sol.push_back(sub_sol);
        for(int i=2;i<=numRows;i++){
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
            dst[i-1]=src[i-2];
            for(int j=1;j<i-1;j++){
                dst[j]=src[j-1]+src[j];
            }
            vector<int> sub_sol;
            for(int j=0;j<i;j++){
                sub_sol.push_back(dst[j]);
            }
            sol.push_back(sub_sol);
        }
        return sol;
    }
};