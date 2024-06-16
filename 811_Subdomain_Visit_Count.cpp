class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>freq;
        for(int i=0;i<cpdomains.size();i++){
            int val=0;
            int j=0;
            while(cpdomains[i][j]>='0' && cpdomains[i][j]<='9'){
                val=val*10+cpdomains[i][j]-'0';
                j++;
            }
            while(cpdomains[i][j]==' '){
                j++;
            }
            freq[cpdomains[i].substr(j)]+=val;
            while(j<cpdomains[i].size()){
                if(cpdomains[i][j]=='.'){
                    freq[cpdomains[i].substr(j+1)]+=val;
                }
                j++;
            }
        }
        vector<string> ans;
        for(auto iter=freq.begin();iter!=freq.end();iter++){
            string s=string(to_string(iter->second)+" "+iter->first);
            ans.push_back(s);
        }
        return ans;
    }
};