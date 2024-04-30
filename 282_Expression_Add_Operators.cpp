class Solution {
public:
    void recursion(string& num,int idx,string curExpr,long long prev_res,long long prev_num,vector<string>& ans,int target){
        if(idx>=num.size()){
            if(prev_res==target){
                ans.push_back(curExpr);
            }
        }
        long long curNum=0;
        for(int i=idx;i<num.size();i++){
            if(num[idx]=='0' && i>idx)return;
            curNum=curNum*10+(num[i]-'0');
            if(idx==0){
                recursion(num,i+1,curExpr+num.substr(idx,i-idx+1),prev_res+curNum,curNum,ans,target);    
            }
            else{
                recursion(num,i+1,curExpr+"+"+num.substr(idx,i-idx+1),prev_res+curNum,curNum,ans,target);
                recursion(num,i+1,curExpr+"-"+num.substr(idx,i-idx+1),prev_res-curNum,(-1)*curNum,ans,target);
                recursion(num,i+1,curExpr+"*"+num.substr(idx,i-idx+1),prev_res-prev_num+prev_num*curNum,prev_num*curNum,ans,target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        recursion(num,0,"",0,0,ans,target);
        return ans;    
    }
};