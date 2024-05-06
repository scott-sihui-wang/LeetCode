class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>freq_p,freq_w;
        vector<int>ans;
        for(int i=0;i<p.size();i++){
            freq_p[p[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(i<p.size()){
                freq_w[s[i]]++;
            }
            else{
                freq_w[s[i]]++;
                freq_w[s[i-p.size()]]--;
            }
            if(i>=p.size()-1){
                unordered_map<char,int>::iterator iter;
                bool matched=true;
                for(iter=freq_w.begin();iter!=freq_w.end();iter++){
                    if(iter->second!=freq_p[iter->first]){
                        matched=false;
                        break;
                    }
                }
                if(matched){
                    ans.push_back(i-p.size()+1);
                }
            }
        }
        return ans;
    }
};