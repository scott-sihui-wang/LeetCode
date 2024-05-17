class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size();
        bool visited[m][n][64];
        memset(visited,false,sizeof(visited));
        queue<pair<pair<int,int>,int>>q;
        int final_status=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]>='a' && grid[i][j]<='f'){
                    final_status= (final_status |  (1<<(grid[i][j]-'a')));
                }
            }
        }
        int step=0;
        vector<vector<int>> direction={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                pair<pair<int,int>,int>p=q.front();
                q.pop();
                int x=p.first.first,y=p.first.second,status=p.second;
                for(int j=0;j<4;j++){
                    if(x+direction[j][0]>=0 && x+direction[j][0]<m && y+direction[j][1]>=0 && y+direction[j][1]<n && visited[x+direction[j][0]][y+direction[j][1]][status]==false){
                        if((grid[x+direction[j][0]][y+direction[j][1]]=='.' || grid[x+direction[j][0]][y+direction[j][1]]=='@') && visited[x+direction[j][0]][y+direction[j][1]][status]==false){
                            visited[x+direction[j][0]][y+direction[j][1]][status]=true;
                            q.push({{x+direction[j][0],y+direction[j][1]},status});
                        }
                        else if(grid[x+direction[j][0]][y+direction[j][1]]>='a' && grid[x+direction[j][0]][y+direction[j][1]]<='f' && visited[x+direction[j][0]][y+direction[j][1]][status|(1<<(grid[x+direction[j][0]][y+direction[j][1]]-'a'))]==false){
                            if((status|(1<<(grid[x+direction[j][0]][y+direction[j][1]]-'a')))==final_status)return step+1;
                            visited[x+direction[j][0]][y+direction[j][1]][status|(1<<(grid[x+direction[j][0]][y+direction[j][1]]-'a'))]=true;
                            q.push({{x+direction[j][0],y+direction[j][1]},(status|(1<<(grid[x+direction[j][0]][y+direction[j][1]]-'a')))});
                        }
                        else if(grid[x+direction[j][0]][y+direction[j][1]]>='A' && grid[x+direction[j][0]][y+direction[j][1]]<='F' && visited[x+direction[j][0]][y+direction[j][1]][status]==false){
                            if((status & (1<<(grid[x+direction[j][0]][y+direction[j][1]]-'A')))!=0){
                                visited[x+direction[j][0]][y+direction[j][1]][status]=true;
                                q.push({{x+direction[j][0],y+direction[j][1]},status});
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};