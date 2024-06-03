class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n<10)return n;
        string s=to_string(n);
        int i=0;
        while(i<s.size()-1 && s[i]<=s[i+1]){
            i++;
        }
        if(i==s.size()-1)return n;
        int j=i;
        while(j>=0 && s[j]==s[i]){
            j--;
        }
        s[j+1]--;
        for(int k=j+2;k<s.size();k++){
            s[k]='9';
        }
        return stoi(s);
    }
};