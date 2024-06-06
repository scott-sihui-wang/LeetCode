class Solution {
public:
    void DFS(string& s,int idx,string& sub,vector<string>& ans){
        if(idx==s.size())ans.push_back(sub);
        if(s[idx]>='0' && s[idx]<='9'){
            sub+=s[idx];
            DFS(s,idx+1,sub,ans);
            sub=sub.substr(0,sub.size()-1);
        }
        else if(s[idx]>='A' && s[idx]<='Z'){
            sub+=s[idx];
            DFS(s,idx+1,sub,ans);
            sub=sub.substr(0,sub.size()-1);
            char c=s[idx]+32;
            sub+=c;
            DFS(s,idx+1,sub,ans);
            sub=sub.substr(0,sub.size()-1);
        }
        else if(s[idx]>='a' && s[idx]<='z'){
            sub+=s[idx];
            DFS(s,idx+1,sub,ans);
            sub=sub.substr(0,sub.size()-1);
            char c=s[idx]-32;
            sub+=c;
            DFS(s,idx+1,sub,ans);
            sub=sub.substr(0,sub.size()-1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string str("");
        DFS(s,0,str,ans);
        return ans; 
    }
};