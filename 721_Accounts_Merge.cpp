class Solution {
public:
    struct disjointSet{
        int *parent;
        disjointSet(int n){
            parent=new int[n];
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        ~disjointSet(){
            delete[] parent;
        }
        int findParent(int x){
            return parent[x]==x?x:findParent(parent[x]);
        }
        void merge(int x,int y){
            int px=findParent(x),py=findParent(y);
            if(px<py){
                parent[py]=px;
            }
            else{
                parent[px]=py;
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> dict;
        disjointSet d(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(dict.find(accounts[i][j])!=dict.end()){
                    d.merge(i,dict[accounts[i][j]]);   
                }
                dict[accounts[i][j]]=d.findParent(i);
            }
        }
        unordered_map<int,vector<string>> merged;
        for(unordered_map<string,int>::iterator iter=dict.begin();iter!=dict.end();iter++){
            merged[d.findParent(iter->second)].push_back(iter->first);
        }
        vector<vector<string>> ans;
        for(unordered_map<int,vector<string>>::iterator iter=merged.begin();iter!=merged.end();iter++){
            vector<string> account;
            account.push_back(accounts[iter->first][0]);
            vector<string> mails;
            for(int i=0;i<iter->second.size();i++){
                mails.push_back(iter->second[i]);
            }
            sort(mails.begin(),mails.end());
            for(int i=0;i<mails.size();i++){
                account.push_back(mails[i]);
            }
            ans.push_back(account);
        }
        return ans;
    }
};