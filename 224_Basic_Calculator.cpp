class Solution {
public:
    int calculate(string s) {
        int curNum=0;
        char curOpr='+';
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                curNum=curNum*10+(s[i]-'0');
            }
            if(i==s.size()-1 ||  (s[i]=='+' || s[i]=='-')){
                if(curOpr=='+'){
                    st.push(curNum);
                }
                else if(curOpr=='-'){
                    st.push((-1)*curNum);
                }
                curNum=0;
                if(i<s.size() && (s[i]=='+' || s[i]=='-'))curOpr=s[i];
                if(i>=s.size()-1){
                    int ans=0;
                    while(!st.empty()){
                        ans+=st.top();
                        st.pop();
                    }
                    return ans;
                }
            }
            else if(s[i]=='('){
                int bracket_idx=1;
                int begin=i,end=i+1;
                while(bracket_idx>0){
                    if(s[end]=='('){
                        bracket_idx++;
                    }
                    else if(s[end]==')'){
                        bracket_idx--;
                    }
                    end++;
                }
                curNum=calculate(s.substr(begin+1,end-begin-2));
                i=(end>s.size()-1?end-2:end-1);
            }
        }
        return 0;
    }
};