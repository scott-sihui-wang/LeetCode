class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0;
        map<vector<int>,int> seq;
        for(int i=0;i<grid.size();i++){
            if(seq.find(grid[i])==seq.end()){
                seq[grid[i]]=1;
            }
            else{
                seq[grid[i]]++;
            }
        }
        for(int i=0;i<grid.size();i++){
            vector<int> v;
            for(int j=0;j<grid.size();j++){
                v.push_back(grid[j][i]);
            }
            if(seq.find(v)!=seq.end()){
                ans+=seq[v];
            }
        }
        return ans;
    }
};