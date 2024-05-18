class Solution {
public:
    bool isAdj(string& s1, string& s2){
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(cnt>1)return false;
            }
        }
        return cnt==1;
    }
    void BFS(vector<vector<int>>& adj, vector<vector<int>>& parent, int n, int src){
        vector<int> dist(n,INT_MAX);
        queue<int>q;
        q.push(src);
        dist[src]=0;
        parent[src].push_back(-1);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int i=0;i<adj[v].size();i++){
                if(dist[adj[v][i]]>dist[v]+1){
                    dist[adj[v][i]]=dist[v]+1;
                    parent[adj[v][i]].clear();
                    parent[adj[v][i]].push_back(v);
                    q.push(adj[v][i]);
                }
                else if(dist[adj[v][i]]==dist[v]+1){
                    parent[adj[v][i]].push_back(v);
                }
            }
        }
    }
    void genPath(vector<vector<int>>& parent,int dst, int src, vector<string>& wordList,vector<string>& path,vector<vector<string>>& ans){
        for(int i=0;i<parent[dst].size();i++){
            path.push_back(wordList[dst]);
            if(dst==src){
                ans.push_back(path);
            }
            else{
                genPath(parent,parent[dst][i],src,wordList,path,ans);
            }
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        bool containBegin=false,containEnd=false;
        int begin,end,n;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==beginWord){
                containBegin=true;
                begin=i;
            }
            else if(wordList[i]==endWord){
                containEnd=true;
                end=i;
            }
        }
        if(!containEnd)return ans;
        if(!containBegin){
            wordList.push_back(beginWord);
            begin=wordList.size()-1;
        }
        n=wordList.size();
        vector<vector<int>>G(n,vector<int>());
        for(int i=0;i<wordList.size()-1;i++){
            for(int j=i+1;j<wordList.size();j++){
                if(isAdj(wordList[i],wordList[j])){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        vector<vector<int>>parent(n,vector<int>());
        BFS(G,parent,n,begin);
        vector<string>path;
        genPath(parent,end,begin,wordList,path,ans);
        for(int i=0;i<ans.size();i++){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};