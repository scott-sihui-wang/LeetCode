class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
        int cur_dir=0;
        int cur_loc[2]={0,0};
        for(int i=0;i<instructions.size();i++){
            if(instructions[i]=='G'){
                cur_loc[0]+=directions[cur_dir][0];
                cur_loc[1]+=directions[cur_dir][1];
            }
            else if(instructions[i]=='R'){
                cur_dir=(cur_dir+1)%4;
            }
            else{
                cur_dir=(cur_dir+3)%4;
            }
        }
        return ((cur_loc[0]==0 && cur_loc[1]==0) || (cur_dir!=0));
    }
};