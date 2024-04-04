class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1=haystack.length();
        int len2=needle.length();
        for(int i=0;i<=len1-len2;i++){
            bool match=true;
            for(int j=0;j<len2;j++){
                if(haystack[i+j]!=needle[j]){
                    match=false;
                    break;
                }
            }
            if(match){
                return i;
            }
        }
        return -1;
    }
};
