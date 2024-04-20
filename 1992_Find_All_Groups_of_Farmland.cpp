class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size(),n=land[0].size();
        bool vis[m][n];
        memset(vis,false,sizeof(vis));
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1 && vis[i][j]==false){
                    vector<int>group;
                    group.push_back(i);
                    group.push_back(j);
                    int k=i,l=j;
                    while(k<m && land[k][j]==1){
                        k++;
                    }
                    --k;
                    group.push_back(k);
                    while(l<n && land[k][l]==1){
                        l++;
                    }
                    --l;
                    group.push_back(l);
                    ans.push_back(group);
                    for(int p=i;p<=k;p++){
                        for(int q=j;q<=l;q++){
                            vis[p][q]=true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};