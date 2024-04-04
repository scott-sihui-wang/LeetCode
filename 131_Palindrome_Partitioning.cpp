class Solution {
public:
    bool isPalindrome(string s){
        int len=s.size();
        for(int i=0;i<len/2;i++){
            if(s[i]!=s[len-i-1])return false;
        }
        return true;
    }
    void partition_backtrack(string s,vector<string>& partial_partition,vector<vector<string>>& ans){
        if (s.size()==0){
            ans.push_back(partial_partition);
        }
        for(int i=1;i<=s.size();i++){
            if (isPalindrome(s.substr(0,i))){
                partial_partition.push_back(s.substr(0,i));
                partition_backtrack(s.substr(i,s.size()-i),partial_partition,ans);
                partial_partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> partial_partition;
        vector<vector<string>> ans;
        partition_backtrack(s,partial_partition,ans);
        return ans;
    }
};