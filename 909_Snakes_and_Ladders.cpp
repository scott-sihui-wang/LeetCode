class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int flatten[n*n];
        int idx=0;
        int dist[n*n];
        memset(dist,-1,sizeof(dist));
        dist[0]=0;
        for(int i=n-1;i>=0;i--){
            if((n-i)%2==1){
                for(int j=0;j<n;j++){
                    flatten[idx++]=board[i][j];
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    flatten[idx++]=board[i][j];
                }
            }
        }
        queue<int> pos;
        pos.push(0);
        while(!pos.empty()){
            int cur_pos=pos.front();
            pos.pop();
            for(int i=cur_pos+1;i<=min(n*n-1,cur_pos+6);i++){
                if(flatten[i]!=-1){
                    if(flatten[i]==n*n){
                        return dist[cur_pos]+1;
                    }
                    if(dist[flatten[i]-1]==-1){
                        pos.push(flatten[i]-1);
                        dist[flatten[i]-1]=dist[cur_pos]+1;
                    }
                }
                else{
                    if(i==n*n-1){
                        return dist[cur_pos]+1;
                    }
                    if(dist[i]==-1){
                        pos.push(i);
                        dist[i]=dist[cur_pos]+1;
                    }
                }
            }
        }
        return dist[n*n-1];                                     
    }
};