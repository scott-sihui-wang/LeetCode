class Solution {
public:
    string num2str(int val){
        string sol;
        int cnt=0;
        while(val>0){
            sol.append(1,val%10+'0');
            val=val/10;
            cnt++;
        }
        for(int i=0;i<cnt/2;i++){
            char c=sol[i];
            sol[i]=sol[cnt-1-i];
            sol[cnt-1-i]=c;
        }
        return sol;
    }
    string convert(string& str){
        int freq[26];
        memset(freq,0,sizeof(freq));
        int len=str.length();
        for(int i=0;i<len;i++){
            freq[str[i]-'a']++;
        }
        string sol;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                sol.append(1,'a'+i);
                sol.append(num2str(freq[i]));
            }
        }
        return sol;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > dict;
        unordered_map<string,vector<string> >::iterator iter;
        for(int i=0;i<strs.size();i++){
            string str_c=convert(strs[i]);
            iter=dict.find(str_c);
            if(iter==dict.end()){
                dict[str_c]=vector<string>(1,strs[i]);
            }
            else{
                iter->second.push_back(strs[i]);
            }
        }
        vector<vector<string> >sol;
        for(iter=dict.begin();iter!=dict.end();iter++){
            vector<string> sub_sol;
            for(int i=0;i<iter->second.size();i++){
                sub_sol.push_back(iter->second[i]);
            }
            sol.push_back(sub_sol);
        }
        return sol;
    }
};