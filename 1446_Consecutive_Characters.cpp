class Solution {
public:
    int maxPower(string s) {
        int len=s.length();
        int i=0;
        int max_len=0;
        while(i<len){
            int start=i;
            while(i+1<len && s[i]==s[i+1]){
                ++i;
            }
            max_len=max(max_len,i-start+1);
            ++i;
        }
        return max_len;
    }
};