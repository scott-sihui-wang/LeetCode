class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.length();
        int i=0;
        int begin=0;
        int end=0;
        while(i<len){
            while(s[i]==' '){
                i++;
            }
            if(i==len)break;
            begin=i;
            while(s[i]!=' ' && i<len){
                i++;
            }
            end=i;
        }
        return end-begin;
    }
};