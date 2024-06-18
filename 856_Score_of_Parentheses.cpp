class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(0);
            }
            else if(s[i]==')'){
                int v=st.top();
                st.pop();
                if(v==0){
                    st.top()+=1;
                }
                else{
                    st.top()+=2*v;
                }
            }
        }
        return st.top();
    }
};