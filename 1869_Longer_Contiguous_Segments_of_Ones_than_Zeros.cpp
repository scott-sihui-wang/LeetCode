class Solution {
public:
    bool checkZeroOnes(string s) {
        int len=s.length();
        int i=0;
        int len_0=0;
        int len_1=0;
        while(i<len){
            int start=i;
            while(i+1<len && s[i]==s[i+1]){
                ++i;
            }
            if(s[i]=='0'){
                len_0=max(len_0,i+1-start);
            }
            else if(s[i]=='1'){
                len_1=max(len_1,i+1-start);
            }
            ++i;
        }
        return (len_1>len_0);
    }
};