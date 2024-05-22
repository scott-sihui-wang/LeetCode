class Solution {
public:
    string convertToTitle(int columnNumber) {
        int i=1;
        long long val=26;
        while(columnNumber-val>=1){
            columnNumber-=val;
            i++;
            val*=26;
        }
        columnNumber--;
        string ans(i,' ');
        for(int j=i-1;j>=0;j--){
            ans[j]=columnNumber%26+'A';
            columnNumber/=26;
        }
        return ans;
    }
};