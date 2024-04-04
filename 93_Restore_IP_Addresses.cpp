class Solution {
public:
    bool Decodable(string sub){
        if(sub.size()==1){
            return true;
        }
        else if(sub.size()==2){
            return sub[0]=='0'?false:true;
        }
        else if(sub.size()==3){
            if(sub[0]=='0'||sub[0]>'2'||(sub[0]=='2'&&sub[1]>'5')||(sub[0]=='2'&&sub[1]=='5'&&sub[2]>'5')){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return false;
        }
    }
    void decode(string s,int step,string& dec,vector<string>& ans){
        if(step==4){
            if(Decodable(s)){
                dec=dec+s;
                ans.push_back(dec);
                dec=dec.substr(0,dec.size()-s.size());
            }
        }
        else if(step<4 && step>0){
            int len=s.size();
            for(int i=1;i<=min(len,3);i++){
                if(Decodable(s.substr(0,i))){
                    dec=dec+s.substr(0,i)+'.';
                    decode(s.substr(i,len-i),step+1,dec,ans);
                    dec=dec.substr(0,dec.size()-i-1);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string dec="";
        vector<string> ans;
        decode(s,1,dec,ans);
        return ans;
    }
};