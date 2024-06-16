class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>freq;
        map<int,vector<char>>freq_ordered;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        for(auto iter=freq.begin();iter!=freq.end();iter++){
            freq_ordered[iter->second].push_back(iter->first);
        }
        auto iter=freq_ordered.rbegin();
        int n=iter->first;
        vector<string>str(n,string(""));
        int idx=0;
        for(;iter!=freq_ordered.rend();iter++){
            for(int i=0;i<iter->second.size();i++){
                for(int j=0;j<iter->first;j++){
                    str[idx]+=string(1,iter->second[i]);
                    idx++;
                    if(idx==n)idx=0;
                }
            }
        }
        string ans=string("");
        if(str.size()>=2 && str[str.size()-2].size()==1){
            return ans;
        }
        for(int i=0;i<str.size();i++){
            ans+=str[i];
        }
        return ans;
    }
};