class Solution {
public:
    string genPal(string n,string& l){
        string left=n.substr(0,n.size()/2+n.size()%2);
        string right;
        if(n.size()%2==0){
            right=left;
        }
        else{
            right=left.substr(0,n.size()/2);
        }
        reverse(right.begin(),right.end());
        l=left;
        string p=left+right;
        return p;
    }
    string genPal(string sub,bool odd){
        string right;
        if(odd){
            right=sub.substr(0,sub.size()-1);
        }
        else{
            right=sub;
        }
        reverse(right.begin(),right.end());
        string p=sub+right;
        return p;
    }
    bool AllZero(string n){
        for(int i=1;i<n.size();i++){
            if(n[i]!='0')return false;
        }
        return true;
    }
    bool InnerZero(string n){
        for(int i=1;i<n.size()-1;i++){
            if(n[i]!='0')return false;
        }
        return true;
    }
    bool AllNine(string n){
        for(int i=0;i<n.size();i++){
            if(n[i]!='9')return false;
        }
        return true;
    }
    string nearestPalindromic(string n) {
        if(stoll(n)<=10)return to_string(stoll(n)-1);
        if(stoll(n)%10==0 && n[0]=='1' && AllZero(n)) return to_string(stoll(n)-1);
        if(stoll(n)==1 || (stoll(n)%10==1 && n[0]=='1' && InnerZero(n))) return to_string(stoll(n)-2);
        if(AllNine(n))return to_string(stoll(n)+2);
        string left;
        string s1=genPal(n,left);
        long long val=stoll(n),val1=stoll(s1);
        if(val==val1){
            string s2=genPal(to_string(stoll(left)-1),n.size()%2==1);
            string s3=genPal(to_string(stoll(left)+1),n.size()%2==1);
            long long val2=stoll(s2);
            long long val3=stoll(s3);
            return val3-val>=val-val2?s2:s3;
        }
        else if(val<val1){
            cout<<"Greater"<<endl;
            cout<<val<<" "<<val1<<endl;
            string s2=genPal(to_string(stoll(left)-1),n.size()%2==1);
            long long val2=stoll(s2);
            cout<<val2<<endl;
            return val-val2>val1-val?s1:s2;
        }
        else{
            cout<<"Less than"<<endl;
            cout<<val<<" "<<val1<<endl;
            string s2=genPal(to_string(stoll(left)+1),n.size()%2==1);
            long long val2=stoll(s2);
            cout<<val2<<endl;
            return val-val1>val2-val?s2:s1;
        }
    }
};