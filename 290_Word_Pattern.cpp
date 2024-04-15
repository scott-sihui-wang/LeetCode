class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int i=0,j=0;
        vector<string> words;
        while(j<s.size()){
            while(j<s.size() && s[j]!=' '){
                j++;
            }
            words.push_back(s.substr(i,j-i));
            if(s[j]==' '){
                j++;
                i=j;
            }
        }
        if(pattern.size()!=words.size())return false;
        unordered_map<char,string> map_ps;
        unordered_map<string,char> map_sp;
        unordered_map<char,string>::iterator iter_ps;
        unordered_map<string,char>::iterator iter_sp;
        for(int k=0;k<pattern.size();k++){
            iter_ps=map_ps.find(pattern[k]);
            iter_sp=map_sp.find(words[k]);
            if(iter_ps==map_ps.end()){
                if(iter_sp==map_sp.end()){
                    map_ps[pattern[k]]=words[k];
                    map_sp[words[k]]=pattern[k];
                }
                else{
                    return false;
                }
            }
            else{
                if(map_ps[pattern[k]]!=words[k] || iter_sp==map_sp.end() || map_sp[words[k]]!=pattern[k]){
                    return false;
                }
            }
        }
        return true;
    }
};