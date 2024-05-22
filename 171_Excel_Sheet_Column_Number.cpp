class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        int n=columnTitle.size();
        long long val=26;
        for(int i=1;i<n;i++){
            ans+=val;
            val*=26;
        }
        int num=0;
        for(int i=0;i<columnTitle.size();i++){
            num=num*26+(columnTitle[i]-'A');
        }
        ans+=num+1;
        return ans;
    }
};