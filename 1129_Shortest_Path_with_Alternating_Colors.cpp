class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>adj_red(n,vector<int>());
        vector<vector<int>>adj_blue(n,vector<int>());
        for(int i=0;i<redEdges.size();i++){
            adj_red[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for(int i=0;i<blueEdges.size();i++){
            adj_blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        bool visited[n][2];
        memset(visited,false,sizeof(visited));
        int dist_red[n],dist_blue[n];
        for(int i=0;i<n;i++){
            dist_red[i]=INT_MAX;
            dist_blue[i]=INT_MAX;
        }
        queue<int> q_red,q_blue;
        q_red.push(0);
        int cnt=1,cnt_next=0;
        int depth=0;
        bool isRed=true;
        while(cnt>0){
            int q=q_red.front();
            q_red.pop();
            cnt--;
            dist_red[q]=min(dist_red[q],depth);
            if(isRed){
                visited[q][0]=true;
                for(int i=0;i<adj_red[q].size();i++){
                    if(visited[adj_red[q][i]][1]==false){
                        q_red.push(adj_red[q][i]);
                        cnt_next++;
                    }
                }
            }
            else{
                visited[q][1]=true;
                for(int i=0;i<adj_blue[q].size();i++){
                    if(visited[adj_blue[q][i]][0]==false){
                        q_red.push(adj_blue[q][i]);
                        cnt_next++;
                    }
                }
            }
            if(cnt==0){
                cnt=cnt_next;
                cnt_next=0;
                depth++;
                if(isRed){
                    isRed=false;
                }
                else{
                    isRed=true;
                }
            }
        }
        memset(visited,false,sizeof(visited));
        q_blue.push(0);
        cnt=1;
        cnt_next=0;
        depth=0;
        isRed=false;
        while(cnt>0){
            int q=q_blue.front();
            q_blue.pop();
            cnt--;
            dist_blue[q]=min(dist_blue[q],depth);
            if(isRed){
                visited[q][1]=true;
                for(int i=0;i<adj_red[q].size();i++){
                    if(visited[adj_red[q][i]][0]==false){
                        q_blue.push(adj_red[q][i]);
                        cnt_next++;
                    }
                }
            }
            else{
                visited[q][0]=true;
                for(int i=0;i<adj_blue[q].size();i++){
                    if(visited[adj_blue[q][i]][1]==false){
                        q_blue.push(adj_blue[q][i]);
                        cnt_next++;
                    }
                }
            }
            if(cnt==0){
                cnt=cnt_next;
                cnt_next=0;
                depth++;
                if(isRed){
                    isRed=false;
                }
                else{
                    isRed=true;
                }
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=min(dist_red[i],dist_blue[i]);
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;
    }
};