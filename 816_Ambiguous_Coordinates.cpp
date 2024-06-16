class Solution {
public:
    bool isInt(string s){
        return (s.size()==1 && s[0]=='0') || (s[0]!='0');
    }
    bool isDecimal(string s,int idx){
        return isInt(s.substr(0,idx)) && s[s.size()-1]!='0';
    }
    void parse(string s, int idx, vector<string>& ans){
        string n1=s.substr(1,idx),n2=s.substr(idx+1,s.size()-2-idx);
        vector<string> n1_s,n2_s;
        if(isInt(n1))n1_s.push_back(n1);
        if(isInt(n2))n2_s.push_back(n2);
        for(int i=1;i<n1.size();i++){
            if(isDecimal(n1,i)){
                n1_s.push_back(string(n1.substr(0,i)+"."+n1.substr(i)));
            }
        }
        for(int i=1;i<n2.size();i++){
            if(isDecimal(n2,i)){
                n2_s.push_back(string(n2.substr(0,i)+"."+n2.substr(i)));
            }
        }
        for(int i=0;i<n1_s.size();i++){
            for(int j=0;j<n2_s.size();j++){
                ans.push_back(string("("+n1_s[i]+", "+n2_s[j]+")"));
            }
        }
    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        for(int i=1;i<=s.size()-3;i++){
            parse(s,i,ans);
        }
        return ans;
    }
};