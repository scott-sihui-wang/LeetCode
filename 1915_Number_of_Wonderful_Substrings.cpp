class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        int freq[1<<10];
        memset(freq,0,sizeof(freq));
        freq[0]=1;
        int XOR=0;
        for(int i=0;i<word.size();i++){
            XOR=XOR^(1<<(word[i]-'a'));
            ans+=freq[XOR];
            for(int j=0;j<10;j++){
                ans+=freq[XOR^(1<<j)];
            }
            freq[XOR]++;
        }
        return ans;
    }
};