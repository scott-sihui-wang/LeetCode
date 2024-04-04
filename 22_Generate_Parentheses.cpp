class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0){
            vector<string> sol;
            string s("");
            sol.push_back(s);
            return sol;
        }
        else if(n==1){
            vector<string> sol;
            string s("()");
            sol.push_back(s);
            return sol;
        }
        else{
            vector<string> sol;
            for(int i=0;i<n;i++){
                vector<string> sol1=generateParenthesis(i);
                vector<string> sol2=generateParenthesis(n-1-i);
                for(int j=0;j<sol1.size();j++){
                    for(int k=0;k<sol2.size();k++){
                        string s("(");
                        s.append(sol1[j]);
                        s.append(")");
                        s.append(sol2[k]);
                        sol.push_back(s);
                    }
                }
            }
            return sol;
        }        
    }
};