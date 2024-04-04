class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt_fresh=0;
        queue<int> rot_loc;
        queue<int> rot_pop;
        int step=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    rot_loc.push(i*n+j);
                }
                else if(grid[i][j]==1){
                    cnt_fresh++;
                }
            }
        }
        while(!rot_loc.empty()){
            while(!rot_loc.empty()){
                rot_pop.push(rot_loc.front());
                rot_loc.pop();
            }
            while(!rot_pop.empty()){
                int loc=rot_pop.front();
                rot_pop.pop();
                int loc_x=loc/n;
                int loc_y=loc%n;
                if(loc_x+1<m && grid[loc_x+1][loc_y]==1){
                    grid[loc_x+1][loc_y]=2;
                    cnt_fresh--;
                    rot_loc.push((loc_x+1)*n+loc_y);
                }
                if(loc_x-1>=0 && grid[loc_x-1][loc_y]==1){
                    grid[loc_x-1][loc_y]=2;
                    cnt_fresh--;
                    rot_loc.push((loc_x-1)*n+loc_y);
                }
                if(loc_y+1<n && grid[loc_x][loc_y+1]==1){
                    grid[loc_x][loc_y+1]=2;
                    cnt_fresh--;
                    rot_loc.push(loc_x*n+loc_y+1);
                }
                if(loc_y-1>=0 && grid[loc_x][loc_y-1]==1){
                    grid[loc_x][loc_y-1]=2;
                    cnt_fresh--;
                    rot_loc.push(loc_x*n+loc_y-1);
                }
            }
            if(!rot_loc.empty()){
                step++;
            }
        }
        if(cnt_fresh==0){
            return step;
        }
        else{
            return -1;
        }
    }
};