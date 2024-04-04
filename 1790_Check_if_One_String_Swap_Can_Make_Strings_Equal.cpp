class Solution {
public:
    bool checkOnesSegment(string s) {
        int len=s.length();
        int i=0;
        int cnt=0;
        while(i<len){
            while(i+1<len && s[i]==s[i+1]){
                i++;
            }
            if(s[i]=='1'){
                cnt++;
            }
            i++;
        }
        return (cnt==1);
    }
};