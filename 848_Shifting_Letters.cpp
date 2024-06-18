class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int offset=0;
        for(int i=s.size()-1;i>=0;i--){
            offset=(offset+shifts[i])%26;
            s[i]=(s[i]-'a'+offset)%26+'a';
        }
        return s;
    }
};