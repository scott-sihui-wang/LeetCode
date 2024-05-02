class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())return string("0");
        stack<char> s;
        int cnt=0;
        for(int i=0;i<num.size();i++){
            while(!s.empty() && s.top()>num[i] && k>0){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }
        string ans("");
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        if(i<ans.size()){
            return ans.substr(i);
        }
        else{
            return string("0");
        }
    }
};