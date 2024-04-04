class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq_s[26];
        int freq_t[26];
        memset(freq_s,0,sizeof(freq_s));
        memset(freq_t,0,sizeof(freq_t));
        int len_s=s.length();
        int len_t=t.length();
        for(int i=0;i<len_s;i++){
            freq_s[s[i]-'a']++;
        }
        for(int i=0;i<len_t;i++){
            freq_t[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq_s[i]!=freq_t[i]){
                return false;
            }
        }
        return true;
    }
};