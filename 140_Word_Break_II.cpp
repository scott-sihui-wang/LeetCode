class Solution {
public:
    bool contain(string s, vector<string>& wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(s==wordDict[i])return true;
        }
        return false;
    }
    void DFS(string sub, vector<string>& wordDict, vector<string>& seg,vector<string>& ans){
        if(sub.size()==0){
            string sol="";
            for(int i=0;i<seg.size()-1;i++){
                sol+=seg[i]+" ";
            }
            sol+=seg[seg.size()-1];
            ans.push_back(sol);
        }
        for(int i=0;i<sub.size();i++){
            if(contain(sub.substr(0,i+1),wordDict)){
                seg.push_back(sub.substr(0,i+1));
                DFS(sub.substr(i+1,sub.size()-i-1),wordDict,seg,ans);
                seg.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        vector<string> seg;
        DFS(s,wordDict,seg,ans);
        return ans;
    }
};