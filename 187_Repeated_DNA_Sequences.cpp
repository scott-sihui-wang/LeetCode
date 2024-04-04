class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> dict;
        unordered_set<string> repeated;
        unordered_set<string>::iterator iter;
        int len=s.size();
        vector<string> ans;
        if(len<=10)return ans;
        for(int i=0;i<s.size()-9;i++){
            iter=dict.find(s.substr(i,10));
            if(iter!=dict.end()){
                repeated.insert(s.substr(i,10));
            }
            else{
                dict.insert(s.substr(i,10));
            }
        }
        for(iter=repeated.begin();iter!=repeated.end();iter++){
            ans.push_back(*iter);
        }
        return ans;
    }
};
