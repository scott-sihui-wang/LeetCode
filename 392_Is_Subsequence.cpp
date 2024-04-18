class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_len=s.size(),t_len=t.size();
        int i=0;
        for(int j=0;j<t_len;j++){
            if(t[j]==s[i]){
                i++;
            }
        }
        return i==s_len;
    }
};