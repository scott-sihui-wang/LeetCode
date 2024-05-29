class Solution {
public:
    string addOne(string s){
        string ans;
        int opr=1;
        int i=s.size()-1;
        while(i>=0 || opr!=0){
            if(i>=0){
                int sum=s[i]-'0'+opr;
                ans+=(sum%2)+'0';
                opr=sum/2;
                i--;
            }
            else{
                ans+=opr+'0';
                opr=0;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int numSteps(string s) {
        int ans=0;
        while(s!="1"){
            if(s[s.size()-1]=='0'){
                s=s.substr(0,s.size()-1);
            }
            else{
                s=addOne(s);
            }
            ans++;
        }
        return ans;
    }
};