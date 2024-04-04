class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int in[n];
        int out[n];
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=0;i<trust.size();i++){
            in[trust[i][1]-1]++;
            out[trust[i][0]-1]++;
        }
        for(int i=0;i<n;i++){
            if(in[i]==n-1 && out[i]==0){
                return i+1;
            }
        }
        return -1;
    }
};