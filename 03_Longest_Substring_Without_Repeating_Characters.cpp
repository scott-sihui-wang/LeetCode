class Solution {
public:
    int solve(string s,int idx,int len){
        int freq[256];
        for(int i=0;i<256;i++){
            freq[i]=0;
        }
        int j;
        for(j=idx;j<len;j++){
            freq[s[j]]++;
            if(freq[s[j]]>1){
                break;
            }
        }
        return j-idx;
    }
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        int longest=0;
        for(int i=0;i<len;i++){
            longest=max(longest,solve(s,i,len));
        }
        return longest;
    }
};