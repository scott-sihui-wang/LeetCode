class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>last_char;
        unordered_map<char,bool>visited;
        for(int i=0;i<s.size();i++){
            last_char[s[i]]=i;
            visited[s[i]]=false;
        }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            while(!st.empty() && visited[s[i]]==false && st.top()>s[i] && last_char[st.top()]>=i){
                visited[st.top()]=false;
                st.pop();
            }
            if(visited[s[i]]==false){
                st.push(s[i]);
                visited[s[i]]=true;
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};