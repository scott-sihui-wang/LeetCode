class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> char_map_st,char_map_ts;
        unordered_map<char,char>::iterator iter_st,iter_ts;
        for(int i=0;i<s.size();i++){
            iter_st=char_map_st.find(s[i]);
            iter_ts=char_map_ts.find(t[i]);
            if(iter_st==char_map_st.end()){
                if(iter_ts==char_map_ts.end()){
                    char_map_st[s[i]]=t[i];
                    char_map_ts[t[i]]=s[i];
                }
                else{
                    return false;
                }                
            }
            else if(char_map_st[s[i]]!=t[i] || iter_ts==char_map_ts.end()){
                return false;
            }
        }
        return true;
    }
};