class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        unordered_set<string>::iterator iter;
        for(int i=0;i<wordDict.size();i++){
            dict.insert(wordDict[i]);
        }
        string query;
        bool dp[s.size()+1];
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<i+1;j++){
                iter=dict.find(s.substr(j,i+1-j));
                dp[i+1]=(dp[j] && iter!=dict.end());
                if(dp[i+1]==true)break;
            }
        }
        return dp[s.size()];
    }
};