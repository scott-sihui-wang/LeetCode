class Solution {
public:
    string compressedString(string word) {
        int prev=0,i=1;
        string ans("");
        while(i<word.size()){
            while(i<word.size() && word[i]==word[prev]){
                i++;
            }
            if(i<word.size()){
                int len=i-prev;
                while(len>=9){
                    ans+='9';
                    ans+=word[prev];
                    len-=9;
                }
                if(len>0){
                    ans+='0'+len;
                    ans+=word[prev];
                }
                prev=i;
            }
        }
        int len=i-prev;
        while(len>=9){
            ans+='9';
            ans+=word[prev];
            len-=9;
        }
        if(len>0){
            ans+='0'+len;
            ans+=word[prev];
        }
        return ans;
    }
};