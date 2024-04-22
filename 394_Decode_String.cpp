class Solution {
public:
    bool isDigit(char c){
        return (c>='0' && c<='9');
    }
    bool isAlpha(char c){
        return (c>='a' && c<='z');
    }
    string decodeString(string s) {
        int val=0;
        string str="";
        stack<int> s_num;
        stack<string> s_str;
        for(int i=0;i<s.size();i++){
            if(isDigit(s[i])){
                val=val*10+(s[i]-'0');
            }
            else if(s[i]=='['){
                s_num.push(val);
                val=0;
                s_str.push(str);
                str="";
            }
            else if(isAlpha(s[i])){
                str=str+s[i];
            }
            else if(s[i]==']'){
                int replic=s_num.top();
                string mul_str="";
                for(int i=0;i<replic;i++){
                    mul_str+=str;
                }
                str=s_str.top()+mul_str;
                s_str.pop();
                s_num.pop();
            }
        }
        return str;
    }
};