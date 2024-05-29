class Solution {
public:
    int findSubstringInWraproundString(string s) {
        if(s.size()==1){
            return 1;
        }
        int len[26];
        memset(len,0,sizeof(len));
        int longest=1;
        int i=1;
        for(;i<s.size();i++){
            if(s[i]==s[i-1]+1 || (s[i]=='a' && s[i-1]=='z')){
                longest++;
            }
            else{
                len[s[i-1]-'a']=max(longest,len[s[i-1]-'a']);
                for(int j=1;j<26;j++){
                    len[((s[i-1]-'a'-j+26)%26)]=max(longest-j,len[((s[i-1]-'a'-j+26)%26)]);
                }
                longest=1;
            }
        }
        len[s[i-1]-'a']=max(longest,len[s[i-1]-'a']);
        for(int j=1;j<26;j++){
            len[((s[i-1]-'a'-j+26)%26)]=max(longest-j,len[((s[i-1]-'a'-j+26)%26)]);
        }
        int ans=0;
        for(int j=0;j<26;j++){
            ans+=len[j];
        }
        return ans;
    }
};