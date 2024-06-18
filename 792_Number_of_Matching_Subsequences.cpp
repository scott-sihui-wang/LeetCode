class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<pair<int,int>>beginWith[26];
        for(int i=0;i<words.size();i++){
            beginWith[words[i][0]-'a'].push_back({i,0});
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<pair<int,int>>affected=beginWith[s[i]-'a'];
            beginWith[s[i]-'a'].clear();
            for(int j=0;j<affected.size();j++){
                if(affected[j].second==words[affected[j].first].size()-1){
                    ans++;
                }
                else{
                    beginWith[words[affected[j].first][affected[j].second+1]-'a'].push_back({affected[j].first,affected[j].second+1});
                }
            }
        }
        return ans;
    }
};