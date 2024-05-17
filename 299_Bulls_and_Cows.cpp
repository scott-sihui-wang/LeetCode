class Solution {
public:
    string getHint(string secret, string guess) {
        int freq_s[10],freq_g[10];
        memset(freq_s,0,sizeof(freq_s));
        memset(freq_g,0,sizeof(freq_g));
        int bull=0,cow=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bull++;
            }
            else{
                freq_s[secret[i]-'0']++;
                freq_g[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            cow+=min(freq_s[i],freq_g[i]);
        }
        string ans=to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};