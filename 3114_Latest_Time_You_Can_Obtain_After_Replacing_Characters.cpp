class Solution {
public:
    string maxH(string s){
        if(s[0]=='?' && s[1]=='?'){
            return string("11");
        }
        else if(s[0]!='?' && s[1]=='?'){
            if(s[0]=='0'){
                return string("09");
            }
            else if(s[0]=='1'){
                return string("11");
            }
            else{
                return string("");
            }
        }
        else if(s[0]=='?' && s[1]!='?'){
            if(s[1]=='0' || s[1]=='1'){
                return string("1")+string(1,s[1]);
            }
            else{
                return string("0")+string(1,s[1]);
            }
        }
        else{
            return s;
        }
    }
    string maxM(string s){
        if(s[0]=='?' && s[1]=='?'){
            return string("59");
        }
        else if(s[0]=='?' && s[1]!='?'){
            return string("5")+string(1,s[1]);
        }
        else if(s[0]!='?' && s[1]=='?'){
            return string(1,s[0])+string("9");
        }
        else{
            return s;
        }
    }
    string findLatestTime(string s) {
        return maxH(s.substr(0,2))+string(":")+maxM(s.substr(3,2));
    }
};