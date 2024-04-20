class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxVowels(string s, int k) {
        int cnt=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i]))cnt++;
        }
        int maximum=cnt;
        if(maximum==k)return k;
        for(int i=k;i<s.size();i++){
            if(isVowel(s[i]))cnt++;
            if(isVowel(s[i-k]))cnt--;
            maximum=max(maximum,cnt);
            if(maximum==k)return k;
        }
        return maximum;
    }
};