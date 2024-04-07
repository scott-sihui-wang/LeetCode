class Solution {
public:
    bool checkValidString(string s) {
        int high=0,low=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                high++;
                low++;
            }
            else if(s[i]==')'){
                high--;
                low--;
            }
            else{
                high++;
                low--;
            }
            if(high<0)return false;
            low=max(low,0);
        }
        if(high>=0 && low<=0){
            return true;
        }
        else{
            return false;
        }
    }
};