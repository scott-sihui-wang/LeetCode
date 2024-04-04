class Solution {
public:
    void solve(int n,int cur,bool vis[],int path[],int& cnt,int k,bool& solved,string& s){
        if(solved==true)return;
        for(int i=0;i<n;i++){
            if(vis[i]==false && solved==false){
                vis[i]=true;
                path[cur-1]=i;
                if(cur==n){
                    ++cnt;
                    if(cnt==k){
                        string str(n,'\0');
                        for(int j=0;j<n;j++){
                            str[j]=path[j]+'1';
                        }
                        s=str;
                        solved=true;
                    }
                }
                else if(solved==false){
                    solve(n,cur+1,vis,path,cnt,k,solved,s);
                }
                vis[i]=false;
            }
        }
    }
    string getPermutation(int n, int k) {
        string sol;
        bool vis[n];
        int path[n];
        int cnt=0;
        bool solved=false;
        memset(vis,0,sizeof(vis));
        memset(path,0,sizeof(path));
        solve(n,1,vis,path,cnt,k,solved,sol);
        return sol;
    }
};