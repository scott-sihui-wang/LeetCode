class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26];
        for(int i=0;i<26;i++){
            freq[i]=0;
        }
        int len=s.length();
        for(int i=0;i<len;i++){
            freq[s[i]-'a']++;
        }
        int i=0;
        while(freq[i]==0){
            i++;
        }
        for(int j=i+1;j<26;j++){
            if(freq[j]!=0 && freq[j]!=freq[i]){
                return false;
            }
        }
        return true;
    }
};