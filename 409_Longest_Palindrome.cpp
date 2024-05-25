class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        int cnt=0;
        for(auto it=freq.begin();it!=freq.end();it++){
            if(it->second%2==1){
                cnt++;
            }
        }
        if(cnt==0){
            return s.size();
        }
        else{
            return s.size()+1-cnt;
        }
    }
};