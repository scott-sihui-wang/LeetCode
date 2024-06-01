class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int i=s.size()-1;
        while(i>0 && s[i-1]>=s[i]){
            i--;
        }
        if(i==0)return -1;
        int j=s.size()-1;
        while(j>i-1 && s[j]<=s[i-1]){
            j--;
        }
        char tmp=s[i-1];
        s[i-1]=s[j];
        s[j]=tmp;
        sort(s.begin()+i,s.end());
        long long val=stoll(s);
        if(val>(long long)INT_MAX){
            return -1;
        }
        else{
            return val;
        }
    }
};