class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.length();
        int len2=word2.length();
        int dist[len1+1][len2+1];
        for(int i=0;i<=len1;i++){
            dist[i][0]=i;
        }
        for(int i=0;i<=len2;i++){
            dist[0][i]=i;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(word1[i-1]==word2[j-1]){
                    dist[i][j]=dist[i-1][j-1];
                }
                else{
                    dist[i][j]=min(min(dist[i-1][j-1],dist[i][j-1]),dist[i-1][j])+1;
                }
            }
        }
        return dist[len1][len2];
    }
};