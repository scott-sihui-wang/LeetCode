class Solution {
public:
    int appendCharacters(string s, string t) {
        int _idx_s=0,_idx_t=0;
        while(_idx_s<s.size() && _idx_t<t.size()){
            if(s[_idx_s]==t[_idx_t]){
                _idx_t++;
            }
            _idx_s++;
        }
        return t.size()-_idx_t;        
    }
};