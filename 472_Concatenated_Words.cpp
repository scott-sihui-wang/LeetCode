class Solution {
public:
    bool DFS(string str,unordered_set<string>& s,int idx,vector<bool>& visited){
        if(idx==str.size())return true;
        if(visited[idx]){
            return false;
        }
        visited[idx]=true;
        for(int i=str.size()-(idx==0?1:0);i>idx;i--){
            if(s.find(str.substr(idx,i-idx))!=s.end()){
                if(DFS(str,s,i,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(),words.end());
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            vector<bool>visited(words[i].size(),false);
            if(DFS(words[i],dict,0,visited)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};