class Solution {
public:
    int percentageLetter(string s, char letter) {
        int len=s.length();
        int cnt=0;
        for(int i=0;i<len;i++){
            if(s[i]==letter){
                cnt++;
            }
        }
        return cnt*100/len;
    }
};