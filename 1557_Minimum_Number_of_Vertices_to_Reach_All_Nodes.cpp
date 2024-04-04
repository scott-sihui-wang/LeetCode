class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int in[n];
        int out[n];
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=0;i<edges.size();i++){
            in[edges[i][1]]++;
        }
        vector<int>sol;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                sol.push_back(i);
            }
        }
        return sol;
    }
};