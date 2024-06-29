class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string>s;
        long long num=1;
        while(num<=INT_MAX){
            string str=to_string(num);
            sort(str.begin(),str.end());
            cout<<str<<endl;
            s.insert(str);
            num*=2;
        }
        string str_n=to_string(n);
        sort(str_n.begin(),str_n.end());
        return s.find(str_n)!=s.end();
    }
};