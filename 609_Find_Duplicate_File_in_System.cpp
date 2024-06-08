class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>dict;
        vector<vector<string>>ans;
        for(int i=0;i<paths.size();i++){
            int j=0;
            while(paths[i][j]!=' '){
                j++;
            }
            string folder_name=paths[i].substr(0,j);
            j++;
            while(j<paths[i].size()){
                int start=j;
                while(j<paths[i].size() && paths[i][j]!='('){
                    j++;
                }
                string file_name=paths[i].substr(start,j-start);
                j++;
                start=j;
                while(j<paths[i].size() && paths[i][j]!=')'){
                    j++;
                }
                string file_content=paths[i].substr(start,j-start);
                string paths=folder_name+"/"+file_name;
                dict[file_content].push_back(paths);
                j+=2;
            }
        }
        for(auto iter=dict.begin();iter!=dict.end();iter++){
            if(iter->second.size()>1){
                ans.push_back(iter->second);
            }
        }
        return ans;
    }
};