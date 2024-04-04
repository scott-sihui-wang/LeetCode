class Solution {
public:
    void sort(vector<int>& arr,int begin,int end){
        if(begin>=end)return;
        int i=begin;
        int j=end;
        int key=arr[begin];
        while(1){
            while(arr[i]<=key){
                i++;
                if(i==end){
                    break;
                }
            }
            while(arr[j]>=key){
                j--;
                if(j==begin){
                    break;
                }
            }
            if(i>=j)break;
            int tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
        arr[begin]=arr[j];
        arr[j]=key;
        sort(arr,begin,j-1);
        sort(arr,j+1,end);
    }
    void dfs(int cur,bool vis[],vector<int>& ans,vector<vector<int> >&sol){
        for(int i=0;i<sol[cur].size();i++){
            if(vis[sol[cur][i]]==false){
                vis[sol[cur][i]]=true;
                ans.push_back(sol[cur][i]);
                dfs(sol[cur][i],vis,ans,sol);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int> >sol;
        vector<vector<int> >ans;
        for(int i=0;i<n;i++){
            vector<int> tmp1;
            vector<int> tmp2;
            sol.push_back(tmp1);
            ans.push_back(tmp2);
        }
        for(int i=0;i<edges.size();i++){
            sol[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            bool vis[n];
            for(int j=0;j<n;j++){
                vis[j]=false;
            }
            vis[i]=true;
            dfs(i,vis,ans[i],sol);
        }
        for(int i=0;i<n;i++){
            sort(ans[i],0,ans[i].size()-1);
        }
        return ans;
    }
};