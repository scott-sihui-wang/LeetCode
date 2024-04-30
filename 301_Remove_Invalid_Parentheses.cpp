class Solution {
public:
    bool isValid(string s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
            }
            if(cnt<0)return false;
        }
        return cnt==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        if(isValid(s)){
            ans.push_back(s);
            return ans;
        }
        queue<string> q;
        q.push(s);
        int cnt=1,cnt_next=0;
        bool isEnd=false;
        unordered_set<string> dict;
        while(!isEnd){
            cnt_next=0;
            while(cnt>0){
                string str=q.front();
                q.pop();
                cnt--;
                for(int i=0;i<str.size();i++){
                    string sub_str=str.substr(0,i)+str.substr(i+1);
                    if(dict.find(sub_str)==dict.end()){
                        dict.insert(sub_str);
                        if(isValid(sub_str)){
                            ans.push_back(sub_str);
                            isEnd=true;
                        }
                        else{
                            q.push(sub_str);
                            cnt_next++;
                        }
                    }
                    
                }
            }
            if(!isEnd)cnt=cnt_next;
        }
        return ans;
    }
};