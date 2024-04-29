class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int len=expression.size();
        bool isNum=true;
        vector<int> ans;
        for(int i=0;i<len;i++){
            if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){
                isNum=false;
                vector<int> left=diffWaysToCompute(expression.substr(0,i));
                vector<int> right=diffWaysToCompute(expression.substr(i+1));
                for(int j=0;j<left.size();j++){
                    for(int k=0;k<right.size();k++){
                        if(expression[i]=='+'){
                            ans.push_back(left[j]+right[k]);
                        }
                        else if(expression[i]=='-'){
                            ans.push_back(left[j]-right[k]);
                        }
                        else if(expression[i]=='*'){
                            ans.push_back(left[j]*right[k]);
                        }
                    }
                }
            }
        }
        if(isNum){
            int num=0;
            for(int i=0;i<expression.size();i++){
                num=num*10+(expression[i]-'0');
            }
            ans.push_back(num);
        }
        return ans;
    }
};