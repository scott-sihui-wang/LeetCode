class Solution {
public:
    string reverseVowels(string s) {
        int len=s.length();
        int pos[len];
        int bound=0;
        for(int i=0;i<len;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                pos[bound++]=i;
            }
        }
        int k=-1;
        if(bound>0){
            if(bound%2==0){
                k=(bound-1)/2;
            }
            else{
                k=bound/2-1;
            }   
        }
        for(int i=0;i<=k;i++){
            char tmp=s[pos[i]];
            s[pos[i]]=s[pos[bound-1-i]];
            s[pos[bound-1-i]]=tmp;
        }
        return s;
    }
};