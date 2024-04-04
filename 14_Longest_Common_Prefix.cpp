class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n1=strs.size();
        int n2=strs[0].length();
        int idx=0;
        for(int i=1;i<n1;i++){
            if(strs[i].length()<n2){
                n2=strs[i].length();
                idx=i;
            }
        }
        int id=0;
        bool common;
        for(;id<n2;id++){
            common=true;
            for(int j=0;j<n1;j++){
                if(j!=idx && strs[idx][id]!=strs[j][id]){
                    common=false;
                    break;
                }
            }
            if(common==false){
                break;
            }
        }
        if(common==true){
            return strs[0].substr(0,n2);
        }
        else{
            if(id==0){
                return string("");
            }
            else{
                return strs[0].substr(0,id);
            }
        }
    }
};