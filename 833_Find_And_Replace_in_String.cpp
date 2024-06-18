class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        map<pair<int,int>,string>replace;
        for(int i=0;i<sources.size();i++){
            int j=0;
            bool matched=true;
            while(j<sources[i].size()){
                if(sources[i][j]!=s[indices[i]+j]){
                    matched=false;
                    break;
                }
                j++;
            }
            if(matched){
                replace[{indices[i],indices[i]+j}]=targets[i];
            }
        }
        auto iter=replace.begin();
        string ans="";
        int idx=0;
        while(idx<s.size()){
            if(iter!=replace.end() && idx<iter->first.first){
                ans+=s[idx];
                idx++;
            }
            else if(iter!=replace.end() && idx==iter->first.first){
                ans+=iter->second;
                idx=iter->first.second;
                iter++;
            }
            else if(iter==replace.end()){
                ans+=s[idx];
                idx++;
            }
        }
        return ans;
    }
};