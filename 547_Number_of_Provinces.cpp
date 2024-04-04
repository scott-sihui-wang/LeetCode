class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        bool vis[n];
        for(int i=0;i<n;i++){
            vis[i]=false;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                cnt++;
                int pos[200];
                pos[0]=i;
                vis[i]=true;
                int left=0;
                int right=1;
                int prev_left;
                while(left<right){
                    prev_left=left;
                    left=right;
                    for(int j=prev_left;j<left;j++){
                        for(int k=0;k<n;k++){
                            if(k!=pos[j] && isConnected[pos[j]][k]==1 && vis[k]==false){
                                vis[k]=true;
                                pos[right++]=k;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};