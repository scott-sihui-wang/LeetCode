class Solution {
public:
    string maskPII(string s) {
        if((s[0]>='A' && s[0]<='Z')||(s[0]>='a' && s[0]<='z')){
            int i=0;
            while(i<s.size() && s[i]!='@'){
                i++;
            }
            string ans="";
            ans+=((s[0]>='A'&&s[0]<='Z')?s[0]-'A'+'a':s[0]);
            ans+=string(5,'*');
            ans+=((s[i-1]>='A'&&s[i-1]<='Z')?s[i-1]-'A'+'a':s[i-1]);
            while(i<s.size()){
                ans+=((s[i]>='A'&&s[i]<='Z')?s[i]-'A'+'a':s[i]);
                i++;
            }
            return ans;
        }
        else{
            string num="";
            for(int i=0;i<s.size();i++){
                if(s[i]>='0' && s[i]<='9'){
                    num+=s[i];
                }
            }
            if(num.size()==10){
                return string("***-***-")+num.substr(6);
            }
            else if(num.size()==11){
                return string("+*-***-***-")+num.substr(7);
            }
            else if(num.size()==12){
                return string("+**-***-***-")+num.substr(8);
            }
            else{
                return string("+***-***-***-")+num.substr(9);
            }
        }
    }
};