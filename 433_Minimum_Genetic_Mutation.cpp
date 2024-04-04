class Solution {
public:
    int diff(string s1,string s2){
        int len=s1.length();
        int cnt=0;
        for(int i=0;i<len;i++){
            if(s1[i]!=s2[i]){
                ++cnt;
            }
        }
        return cnt;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int len=bank.size();
        if(len==0)return -1;
        bool vis[len];
        string str_list[len+1];
        memset(vis,0,sizeof(vis));
        bool valid=false;
        for(int i=0;i<bank.size();i++){
            if(bank[i]==start){
                vis[i]=true;
            }
            if(bank[i]==end){
                valid=true;
            }
        }
        if(valid==false)return -1;
        str_list[0]=start;
        int left=0;
        int right=1;
        int prev_left;
        int dist=0;
        while(left<right){
            prev_left=left;
            left=right;
            dist++;
            for(int i=prev_left;i<left;i++){
                for(int j=0;j<len;j++){
                    if(vis[j]==false && diff(str_list[i],bank[j])==1){
                        str_list[right++]=bank[j];
                        vis[j]=true;
                        if(bank[j]==end){
                            return dist;
                        }
                    }
                }
            }
        }
        return -1;
    }
};