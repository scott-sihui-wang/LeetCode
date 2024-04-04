class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int stat_r[26];
        int stat_m[26];
        for(int i=0;i<26;i++){
            stat_r[i]=0;
            stat_m[i]=0;
        }
        int len_r=ransomNote.length();
        int len_m=magazine.length();
        for(int i=0;i<len_m;i++){
            stat_m[magazine[i]-'a']++;
        }
        for(int i=0;i<len_r;i++){
            stat_r[ransomNote[i]-'a']++;
        }
        bool sol=true;
        for(int i=0;i<26;i++){
            if(stat_r[i]>stat_m[i]){
                sol=false;
                break;
            }
        }
        return sol;
    }
};