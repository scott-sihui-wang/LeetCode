class Solution {
public:
    int longestSubstring(string s, int k) {
        int freq[26];
        int uniCh=0;
        memset(freq,0,sizeof(freq));
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']==0){
                uniCh++;
            }
            freq[s[i]-'a']++;
        }
        int ans=0;
        for(int i=1;i<=uniCh;i++){
            int left=0,right=0,uni=0,uniK=0;
            memset(freq,0,sizeof(freq));
            while(right<s.size()){
                while(right<s.size() && uni<=i){
                    if(freq[s[right]-'a']==0){
                        uni++;
                    }
                    freq[s[right]-'a']++;
                    if(freq[s[right]-'a']==k){
                        uniK++;
                    }
                    right++;
                }
                if(uni<=i){
                    if(uniK==uni){
                        ans=max(ans,right-left);
                    }
                }
                else{
                    if(uniK==uni-1){
                        ans=max(ans,right-left-1);
                    }
                    while(left<s.size() && left<right && uni>i){
                        if(freq[s[left]-'a']==k){
                            uniK--;
                        }
                        freq[s[left]-'a']--;
                        if(freq[s[left]-'a']==0)uni--;
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};