class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len=original.size();
        if(m*n!=len){
            vector<vector<int> >sol;
            return sol;
        }
        vector<vector<int> >sol(m,vector<int>(n));
        for(int i=0;i<len;i++){
            sol[i/n][i%n]=original[i];
        }
        return sol;
    }
};