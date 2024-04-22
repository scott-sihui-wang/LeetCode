class Solution {
public:
    string num2Str(int i1,int i2,int i3,int i4){
        string ret="";
        ret+=i1+'0';
        ret+=i2+'0';
        ret+=i3+'0';
        ret+=i4+'0';
        return ret;
    }
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000")return 0;
        int dest[4]={target[0]-'0',target[1]-'0',target[2]-'0',target[3]-'0'};
        bool visited[10][10][10][10];
        memset(visited,false,sizeof(visited));
        visited[0][0][0][0]=true;
        for(int i=0;i<deadends.size();i++){
            if(deadends[i][0]=='0' && deadends[i][1]=='0' && deadends[i][2]=='0' && deadends[i][3]=='0')return -1;
            visited[deadends[i][0]-'0'][deadends[i][1]-'0'][deadends[i][2]-'0'][deadends[i][3]-'0']=true;
        }
        queue<string> q;
        q.push(string("0000"));
        int round=0;
        int cnt=1;
        while(!q.empty()){
            round++;
            int cnt_next=0;
            while(cnt>0){
                string cur=q.front();
                q.pop();
                cnt--;
                if(visited[(cur[0]-'0'+11)%10][cur[1]-'0'][cur[2]-'0'][cur[3]-'0']==false){
                    if((cur[0]-'0'+11)%10==dest[0] && cur[1]-'0'==dest[1] && cur[2]-'0'==dest[2] && cur[3]-'0'==dest[3])return round;
                    q.push(num2Str((cur[0]-'0'+11)%10,cur[1]-'0',cur[2]-'0',cur[3]-'0'));
                    visited[(cur[0]-'0'+11)%10][cur[1]-'0'][cur[2]-'0'][cur[3]-'0']=true;
                    cnt_next++;
                }
                if(visited[(cur[0]-'0'+9)%10][cur[1]-'0'][cur[2]-'0'][cur[3]-'0']==false){
                    if((cur[0]-'0'+9)%10==dest[0] && cur[1]-'0'==dest[1] && cur[2]-'0'==dest[2] && cur[3]-'0'==dest[3])return round;
                    q.push(num2Str((cur[0]-'0'+9)%10,cur[1]-'0',cur[2]-'0',cur[3]-'0'));
                    visited[(cur[0]-'0'+9)%10][cur[1]-'0'][cur[2]-'0'][cur[3]-'0']=true;
                    cnt_next++;
                }
                if(visited[cur[0]-'0'][(cur[1]-'0'+11)%10][cur[2]-'0'][cur[3]-'0']==false){
                    if(cur[0]-'0'==dest[0] && (cur[1]-'0'+11)%10==dest[1] && cur[2]-'0'==dest[2] && cur[3]-'0'==dest[3])return round;
                    q.push(num2Str(cur[0]-'0',(cur[1]-'0'+11)%10,cur[2]-'0',cur[3]-'0'));
                    visited[cur[0]-'0'][(cur[1]-'0'+11)%10][cur[2]-'0'][cur[3]-'0']=true;
                    cnt_next++;
                }
                if(visited[cur[0]-'0'][(cur[1]-'0'+9)%10][cur[2]-'0'][cur[3]-'0']==false){
                    if(cur[0]-'0'==dest[0] && (cur[1]-'0'+9)%10==dest[1] && cur[2]-'0'==dest[2] && cur[3]-'0'==dest[3])return round;
                    q.push(num2Str(cur[0]-'0',(cur[1]-'0'+9)%10,cur[2]-'0',cur[3]-'0'));
                    visited[cur[0]-'0'][(cur[1]-'0'+9)%10][cur[2]-'0'][cur[3]-'0']=true;
                    cnt_next++;
                }
                if(visited[cur[0]-'0'][cur[1]-'0'][(cur[2]-'0'+11)%10][cur[3]-'0']==false){
                    if(cur[0]-'0'==dest[0] && cur[1]-'0'==dest[1] && (cur[2]-'0'+11)%10==dest[2] && cur[3]-'0'==dest[3])return round;
                    q.push(num2Str(cur[0]-'0',cur[1]-'0',(cur[2]-'0'+11)%10,cur[3]-'0'));
                    visited[cur[0]-'0'][cur[1]-'0'][(cur[2]-'0'+11)%10][cur[3]-'0']=true;
                    cnt_next++;
                }
                if(visited[cur[0]-'0'][cur[1]-'0'][(cur[2]-'0'+9)%10][cur[3]-'0']==false){
                    if(cur[0]-'0'==dest[0] && cur[1]-'0'==dest[1] && (cur[2]-'0'+9)%10==dest[2] && cur[3]-'0'==dest[3])return round;
                    q.push(num2Str(cur[0]-'0',cur[1]-'0',(cur[2]-'0'+9)%10,cur[3]-'0'));
                    visited[cur[0]-'0'][cur[1]-'0'][(cur[2]-'0'+9)%10][cur[3]-'0']=true;
                    cnt_next++;
                }
                if(visited[cur[0]-'0'][cur[1]-'0'][cur[2]-'0'][(cur[3]-'0'+11)%10]==false){
                    if(cur[0]-'0'==dest[0] && cur[1]-'0'==dest[1] && cur[2]-'0'==dest[2] && (cur[3]-'0'+11)%10==dest[3])return round;
                    q.push(num2Str(cur[0]-'0',cur[1]-'0',cur[2]-'0',(cur[3]-'0'+11)%10));
                    visited[cur[0]-'0'][cur[1]-'0'][cur[2]-'0'][(cur[3]-'0'+11)%10]=true;
                    cnt_next++;
                }
                if(visited[cur[0]-'0'][cur[1]-'0'][cur[2]-'0'][(cur[3]-'0'+9)%10]==false){
                    if(cur[0]-'0'==dest[0] && cur[1]-'0'==dest[1] && cur[2]-'0'==dest[2] && (cur[3]-'0'+9)%10==dest[3])return round;
                    q.push(num2Str(cur[0]-'0',cur[1]-'0',cur[2]-'0',(cur[3]-'0'+9)%10));
                    visited[cur[0]-'0'][cur[1]-'0'][cur[2]-'0'][(cur[3]-'0'+9)%10]=true;
                    cnt_next++;
                }
            }
            cnt=cnt_next;   
        }
        return -1;
    }
};