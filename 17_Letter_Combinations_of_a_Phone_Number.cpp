class Solution {
public:
    int choice[8]={3,3,3,3,3,4,3,4};
    char start[8]={'a','d','g','j','m','p','t','w'};
    void solve(string digits,int idx,int len, char* sub_sol, vector<string>& sol){
        int offset=digits[idx]-'2';
        for(int i=0;i<choice[offset];i++){
            sub_sol[idx]=start[offset]+i;
            if(idx==len-1){
                sub_sol[idx+1]='\0';
                sol.push_back(string(sub_sol));
            }
            else{
                solve(digits,idx+1,len,sub_sol,sol);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> sol;
        if(digits==""){
            return sol;
        }
        char sub_sol[5];
        int len=digits.length();
        solve(digits,0,len,sub_sol,sol);
        return sol;
    }
};
