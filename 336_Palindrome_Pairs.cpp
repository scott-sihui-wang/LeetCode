class Solution {
public:
    unordered_map<string,bool> pal_dict;
    bool isPalindrome(string& s){
        if(pal_dict.find(s)!=pal_dict.end()){
            return pal_dict[s];
        }
        int n=s.size();
        if(n==0)return pal_dict[s]=true;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i])return pal_dict[s]=false;
        }
        return pal_dict[s]=true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> rev_dict;
        for(int i=0;i<words.size();i++){
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            rev_dict[rev]=i;
        }
        vector<vector<int>>ans;
        if(rev_dict.find("")!=rev_dict.end()){
            for(int i=0;i<words.size();i++){
                if(rev_dict[""]!=i && isPalindrome(words[i])){
                    ans.push_back({i,rev_dict[""]});
                }
            }
        }
        for(int i=0;i<words.size();i++){
            string begin="",end=words[i];
            for(int j=0;j<words[i].size();j++){
                begin.push_back(words[i][j]);
                end.erase(end.begin());
                if(rev_dict.find(end)!=rev_dict.end() && rev_dict[end]!=i && isPalindrome(begin)){
                    ans.push_back({rev_dict[end],i});
                }
                if(rev_dict.find(begin)!=rev_dict.end() && rev_dict[begin]!=i && isPalindrome(end)){
                    ans.push_back({i,rev_dict[begin]});
                }
            }
        }
        return ans;
    }
};