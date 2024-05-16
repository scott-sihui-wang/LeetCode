class Solution {
public:
    int str2num(string s){
        int ans=0;
        ans=ans*10+s[0]-'0';
        ans=ans*10+s[1]-'0';
        return ans;
    }
    bool lessOrEqual(string s1,string s2){
        int h1=str2num(s1.substr(0,2));
        int m1=str2num(s1.substr(3,2));
        int h2=str2num(s2.substr(0,2));
        int m2=str2num(s2.substr(3,2));
        return h1<h2 || (h1==h2 && m1<=m2);
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return lessOrEqual(event1[0],event2[0])?lessOrEqual(event2[0],event1[1]):lessOrEqual(event1[0],event2[1]);
    }
};