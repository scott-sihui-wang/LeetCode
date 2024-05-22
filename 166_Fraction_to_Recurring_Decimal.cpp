class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans("");
        if((numerator>0 && denominator<0) || (numerator<0 && denominator>0)){
            ans+='-';
        }
        long long n=labs(numerator),d=labs(denominator);
        long long q=n/d;
        long long r=n%d;
        ans+=to_string(q);
        unordered_map<int,int>dict;
        if(r!=0){
            ans+='.';
        }
        while(r!=0){
            if(dict.find(r)!=dict.end()){
                ans+=')';
                ans=ans.substr(0,dict[r])+"("+ans.substr(dict[r]);
                break;
            }
            else{
                dict[r]=ans.size();
                r=r*10;
                q=r/d;
                r=r%d;
                ans+=to_string(q);
            }
        }
        return ans;
    }
};