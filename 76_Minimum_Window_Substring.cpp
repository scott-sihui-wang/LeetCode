class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>t_freq;
        unordered_map<char,int>::iterator iter;
        int t_ttl=t.size();
        int min_idx=-1,min_len=INT_MAX;
        for(int i=0;i<t.size();i++){
            iter=t_freq.find(t[i]);
            if(iter==t_freq.end()){
                t_freq[t[i]]=1;
            }
            else{
                t_freq[t[i]]++;
            }
        }
        int l=0,r=0;
        while(r<s.size()){
            while(r<s.size() && t_ttl>0){
                iter=t_freq.find(s[r]);
                if(iter!=t_freq.end()){
                    t_freq[s[r]]--;
                    if(t_freq[s[r]]>=0)t_ttl--;
                }
                r++;
            }
            while(l<=r && t_ttl<=0){
                iter=t_freq.find(s[l]);
                if(iter!=t_freq.end()){
                    t_freq[s[l]]++;
                    if(t_freq[s[l]]>0)t_ttl++;
                }
                l++;
            }
            if(r-l+1<min_len){
                min_len=r-l+1;
                min_idx=l-1;
            }
        }
        if(min_idx<0){
            return string("");
        }
        else{
            return s.substr(min_idx,min_len);
        }
    }
};