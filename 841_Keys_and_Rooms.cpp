class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int num_room=rooms.size();
        bool vis[num_room];
        for(int i=0;i<num_room;i++){
            vis[i]=false;
        }
        int pos[num_room];
        pos[0]=0;
        vis[0]=true;
        int left=0;
        int right=1;
        int prev_left;
        while(left<right){
            prev_left=left;
            left=right;
            for(int i=prev_left;i<left;i++){
                for(int j=0;j<rooms[pos[i]].size();j++){
                    if(vis[rooms[pos[i]][j]]==false){
                        pos[right++]=rooms[pos[i]][j];
                        vis[rooms[pos[i]][j]]=true;
                    }
                }
            }
        }
        for(int i=1;i<num_room;i++){
            if(vis[i]==false){
                return false;
            }
        }
        return true;
    }
};