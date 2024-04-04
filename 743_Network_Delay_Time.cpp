class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dist[n];
        bool vis[n];
        int len=times.size();
        for(int i=0;i<n;i++){
            dist[i]=1000000;
            vis[i]=false;
        }
        dist[k-1]=0;
        for(int i=0;i<n;i++){
            int dist_min=1000000;
            int v_min=-1;
            for(int j=0;j<n;j++){
                if(vis[j]==false && dist[j]<dist_min){
                    dist_min=dist[j];
                    v_min=j;
                }
            }
            if(v_min!=-1){
                vis[v_min]=true;
                for(int j=0;j<len;j++){
                    if(times[j][0]==v_min+1 && vis[times[j][1]-1]==false && dist[times[j][1]-1]>dist[times[j][0]-1]+times[j][2]){
                        dist[times[j][1]-1]=dist[times[j][0]-1]+times[j][2];
                    }
                }
            }
        }
        int d=0;
        for(int i=0;i<n;i++){
            if(dist[i]>d){
                d=dist[i];
            }
        }
        if(d==1000000){
            return -1;
        }
        else{
            return d;
        }
    }
};