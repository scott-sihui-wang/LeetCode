class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,vector<int>>dict_x,dict_y;
        for(int i=0;i<obstacles.size();i++){
            dict_x[obstacles[i][0]].push_back(obstacles[i][1]);
            dict_y[obstacles[i][1]].push_back(obstacles[i][0]);
        }
        for(auto iter=dict_x.begin();iter!=dict_x.end();iter++){
            sort(iter->second.begin(),iter->second.end());
        }
        for(auto iter=dict_y.begin();iter!=dict_y.end();iter++){
            sort(iter->second.begin(),iter->second.end());
        }
        int ans=0;
        int d=0,x=0,y=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                d=(d+1)%4;
            }
            else if(commands[i]==-2){
                d=(d+3)%4;
            }
            else{
                if(d==0){
                    int y1=y+commands[i];
                    int obs=INT_MIN;
                    for(auto iter=dict_x[x].begin();iter!=dict_x[x].end() && *iter<=y1;iter++){
                        if(*iter>y && *iter<=y1){
                            obs=*iter;
                            break;
                        }
                    }
                    if(obs!=INT_MIN){
                        y1=obs-1;
                    }
                    y=y1;
                }
                else if(d==1){
                    int x1=x+commands[i];
                    int obs=INT_MIN;
                    for(auto iter=dict_y[y].begin();iter!=dict_y[y].end() && *iter<=x1;iter++){
                        if(*iter>x && *iter<=x1){
                            obs=*iter;
                            break;
                        }
                    }
                    if(obs!=INT_MIN){
                        x1=obs-1;
                    }
                    x=x1;
                }
                else if(d==2){
                    int y1=y-commands[i];
                    int obs=INT_MIN;
                    for(auto iter=dict_x[x].rbegin();iter!=dict_x[x].rend() && *iter>=y1;iter++){
                        if(*iter<y && *iter>=y1){
                            obs=*iter;
                            break;
                        }
                    }
                    if(obs!=INT_MIN){
                        y1=obs+1;
                    }
                    y=y1;
                }
                else if(d==3){
                    int x1=x-commands[i];
                    int obs=INT_MIN;
                    for(auto iter=dict_y[y].rbegin();iter!=dict_y[y].rend() && *iter>=x1;iter++){
                        if(*iter<x && *iter>=x1){
                            obs=*iter;
                            break;
                        }
                    }
                    if(obs!=INT_MIN){
                        x1=obs+1;
                    }
                    x=x1;
                }
                ans=max(ans,x*x+y*y);
            }
        }
        return ans;
    }
};