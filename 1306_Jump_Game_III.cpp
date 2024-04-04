class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int len=arr.size();
        bool vis[len];
        for(int i=0;i<len;i++){
            vis[i]=false;
        }
        int pos[len];
        pos[0]=start;
        vis[start]=true;
        int left=0;
        int right=1;
        int prev_left;
        while(left<right){
            prev_left=left;
            left=right;
            for(int i=prev_left;i<left;i++){
                if(pos[i]-arr[pos[i]]>=0 && vis[pos[i]-arr[pos[i]]]==false){
                    vis[pos[i]-arr[pos[i]]]=true;
                    pos[right++]=pos[i]-arr[pos[i]];
                }
                if(pos[i]+arr[pos[i]]<len && vis[pos[i]+arr[pos[i]]]==false){
                    vis[pos[i]+arr[pos[i]]]=true;
                    pos[right++]=pos[i]+arr[pos[i]];
                }
            }
        }
        for(int i=0;i<len;i++){
            if(vis[i]==true && arr[i]==0){
                return true;
            }
        }
        return false;
    }
};