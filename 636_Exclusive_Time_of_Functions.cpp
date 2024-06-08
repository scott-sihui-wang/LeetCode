class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>ans(n,0);
        stack<vector<int>>s;
        for(int i=0;i<logs.size();i++){
            int j=0;
            while(logs[i][j]!=':'){
                j++;
            }
            int id=stoi(logs[i].substr(0,j));
            j++;
            bool is_start=(logs[i][j]=='s');
            while(logs[i][j]!=':'){
                j++;
            }
            j++;
            int timestamp=stoi(logs[i].substr(j));
            if(is_start){
                if(!s.empty()){
                    s.top()[2]+=timestamp-s.top()[1];
                    ans[s.top()[0]]+=timestamp-s.top()[1];
                }
                vector<int> info(3,0);
                info[0]=id;
                info[1]=timestamp;
                s.push(info);
            }
            else{
                s.top()[2]=timestamp+1-s.top()[1];
                ans[s.top()[0]]+=timestamp+1-s.top()[1];
                s.pop();
                if(!s.empty()){
                    s.top()[1]=timestamp+1;
                }
            }
        }
        return ans;
    }
};