class Solution {
public:
    int countHomogenous(string s) {
        int len=s.length();
        long long freq[len];
        int top=-1;
        long long sum=0;
        int i=0;
        while(i<len){
            int start=i;
            while(i+1<len && s[i]==s[i+1]){
                i++;
            }
            long long tmp=i-start+1;
            freq[++top]=tmp;
            sum+=(tmp)*(tmp+1)/2;
            i++;
        }
        int m=1e9+7;
        return sum%m;
    }
};