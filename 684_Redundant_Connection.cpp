class Solution {
public:
    int find(int x,int pa[]){
        if(x==pa[x])return x;
        return find(pa[x],pa);
    }
    bool Union(int x,int y,int pa[]){
        int root_x=find(x,pa);
        int root_y=find(y,pa);
        if(root_x==root_y)return false;
        pa[root_x]=root_y;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int len=edges.size();
        int pa[len];
        for(int i=0;i<len;i++){
            pa[i]=i;
        }
        for(int i=0;i<len;i++){
            if(Union(edges[i][0]-1,edges[i][1]-1,pa)==false){
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                return ans;
            }
        }
        return ans;
    }
};