class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int curNum=0;
        int curOpr='+';
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                curNum=curNum*10+(s[i]-'0');
            }
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || i==s.size()-1){
                if(curOpr=='+'){
                    st.push(curNum);
                }
                else if(curOpr=='-'){
                    st.push((-1)*curNum);
                }
                else if(curOpr=='*'){
                    int n=st.top();
                    st.pop();
                    st.push(n*curNum);
                }
                else if(curOpr=='/'){
                    int n=st.top();
                    st.pop();
                    st.push(n/curNum);
                }
                curOpr=s[i];
                curNum=0;
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};