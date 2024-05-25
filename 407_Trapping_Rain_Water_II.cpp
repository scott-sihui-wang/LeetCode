class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size(),n=heightMap[0].size();
        vector<pair<int,pair<int,int>>>boundary;
        bool visited[m][n];
        memset(visited,false,sizeof(visited));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<m;i++){
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][n-1],{i,n-1}});
            visited[i][0]=true;
            visited[i][n-1]=true;
        }
        for(int i=0;i<n;i++){
            pq.push({heightMap[0][i],{0,i}});
            pq.push({heightMap[m-1][i],{m-1,i}});
            visited[0][i]=true;
            visited[m-1][i]=true;
        }
        int ans=0,minH=0;
        while(!pq.empty()){
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            minH=max(minH,p.first);
            int x=p.second.first,y=p.second.second;
            if(x+1>0 && x+1<m-1 && y>0 && y<n-1 && visited[x+1][y]==false){
                if(heightMap[x+1][y]<minH){
                    ans+=minH-heightMap[x+1][y];
                }
                pq.push({heightMap[x+1][y],{x+1,y}});
                visited[x+1][y]=true;
            }
            if(x-1>0 && x-1<m-1 && y>0 && y<n-1 && visited[x-1][y]==false){
                if(heightMap[x-1][y]<minH){
                    ans+=minH-heightMap[x-1][y];
                }
                pq.push({heightMap[x-1][y],{x-1,y}});
                visited[x-1][y]=true;
            }
            if(x>0 && x<m-1 && y+1>0 && y+1<n-1 && visited[x][y+1]==false){
                if(heightMap[x][y+1]<minH){
                    ans+=minH-heightMap[x][y+1];
                }
                pq.push({heightMap[x][y+1],{x,y+1}});
                visited[x][y+1]=true;
            }
            if(x>0 && x<m-1 && y-1>0 && y-1<n-1 && visited[x][y-1]==false){
                if(heightMap[x][y-1]<minH){
                    ans+=minH-heightMap[x][y-1];
                }
                pq.push({heightMap[x][y-1],{x,y-1}});
                visited[x][y-1]=true;
            }
        }
        return ans;
    }
};