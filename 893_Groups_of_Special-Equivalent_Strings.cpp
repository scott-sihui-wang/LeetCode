class Solution {
public:
    string calcEquiv(string w){
        string w_odd="",w_even="";
        for(int i=0;i<w.size();i++){
            if(i%2==0){
                w_even+=w[i];
            }
            else{
                w_odd+=w[i];
            }
        }
        sort(w_odd.begin(),w_odd.end());
        sort(w_even.begin(),w_even.end());
        string ans="";
        for(int i=0;i<w_odd.size();i++){
            ans+=w_even[i];
            ans+=w_odd[i];
        }
        if(w_even.size()>w_odd.size()){
            ans+=w_even[w_even.size()-1];
        }
        return ans;
    }
    int numSpecialEquivGroups(vector<string>& words) {
        set<string>s;
        for(int i=0;i<words.size();i++){
            string str=calcEquiv(words[i]);
            if(s.find(str)==s.end()){
                s.insert(str);
            }
        }
        return s.size();
    }
};