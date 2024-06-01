class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool inBlock=false;
        string line;
        for(int i=0;i<source.size();i++){
            int n=source[i].size();
            if(!inBlock)line="";
            for(int j=0;j<n;j++){
                if(inBlock==false && j<n-1 && source[i][j]=='/' && source[i][j+1]=='*'){
                    inBlock=true;
                    j++;
                }
                else if(j<n-1 && inBlock && source[i][j]=='*' && source[i][j+1]=='/'){
                    inBlock=false;
                    j++;
                }
                else if(inBlock==false && j<n-1 && source[i][j]=='/' && source[i][j+1]=='/'){
                    break;
                }
                else if(inBlock==false){
                    line+=source[i][j];
                }
            }
            if(line.size()>0 && inBlock==false){
                ans.push_back(line);
            }
        }
        return ans;
    }
};