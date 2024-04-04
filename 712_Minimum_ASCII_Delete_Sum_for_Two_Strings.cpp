class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1=s1.length();
        int len2=s2.length();
        int sum[len1+1][len2+1];
        sum[0][0]=0;
        for(int i=1;i<=len1;i++){
            sum[i][0]=sum[i-1][0]+s1[i-1];
        }
        for(int i=1;i<=len2;i++){
            sum[0][i]=sum[0][i-1]+s2[i-1];
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i-1]==s2[j-1]){
                    sum[i][j]=sum[i-1][j-1];
                }
                else{
                    sum[i][j]=min(sum[i-1][j]+s1[i-1],sum[i][j-1]+s2[j-1]);
                }
            }
        }
        return sum[len1][len2];
    }
};