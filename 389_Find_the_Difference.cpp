class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq_s[26]={};
        int freq_t[26]={};
        int len_s=s.length();
        int len_t=t.length();
        for(int i=0;i<len_s;i++){
            freq_s[s[i]-'a']++;
        }
        for(int i=0;i<len_t;i++){
            freq_t[t[i]-'a']++;
        }
        int i=0;
        for(;i<26;i++){
            if(freq_s[i]!=freq_t[i]){
                break;
            }
        }
        return 'a'+i;
    }
};