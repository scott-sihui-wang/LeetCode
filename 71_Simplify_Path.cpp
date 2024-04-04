class Solution {
public:
    string simplifyPath(string path) {
        list<string> directories;
        string ans="";
        string name="";
        bool isName=false;
        //int cnt_dot=0;
        //bool isDot=false;
        //bool isName=false;
        //int name_left_idx,name_right_idx;
        int i=0;
        while(i<path.size()){
            if(path[i]=='/' && isName==true){
                if(name==".."){
                    if(!directories.empty()){
                        directories.pop_back();
                    }
                }
                else if(name!="."){
                    directories.push_back(name);
                }
                isName=false;
                name="";
            }
            else if(path[i]!='/'){
                if(isName==false){
                    isName=true;
                }
                name+=path[i];
            }
            i++;
        }
        if(isName==true){
            if(name==".."){
                if(!directories.empty()){
                    directories.pop_back();
                }
            }
            else if(name!="."){
                directories.push_back(name);
            }
        }
        /*while(i<path.size()){
            if(path[i]=='/'){
                if(isDot==true && isName==true){
                    name_right_idx=i-1;
                    directories.push_back(string(cnt_dot,'.')+path.substr(name_left_idx,name_right_idx+1-name_left_idx));
                }
                else if(isDot==true){
                    if(cnt_dot>=3){
                        directories.push_back(string(cnt_dot,'.'));
                    }
                    else if(cnt_dot==2){
                        if(!directories.empty()){
                            directories.pop_back();
                        }
                    }
                }
                else if(isName==true){
                    name_right_idx=i-1;
                    directories.push_back(path.substr(name_left_idx,name_right_idx+1-name_left_idx));
                }
                cnt_dot=0;
                isName=false;
                isDot=false;
                i++;
            }
            else if(path[i]=='.'){
                if(isDot==false){
                    isDot=true;
                }
                cnt_dot++;
                i++;
            }
            else{
                if(isName==false){
                    isName=true;
                    name_left_idx=i;
                }
                i++;
            }
        }
        if(isDot==true && isName==true){
            name_right_idx=i-1;
            directories.push_back(string(cnt_dot,'.')+path.substr(name_left_idx,name_right_idx+1-name_left_idx));
        }
        else if(isDot==true){
            if(cnt_dot>=3){
                directories.push_back(string(cnt_dot,'.'));
            }
            else if(cnt_dot==2){
                if(!directories.empty()){
                    directories.pop_back();
                }
            }
        }
        else if(isName==true){
            name_right_idx=i-1;
            directories.push_back(path.substr(name_left_idx,name_right_idx+1-name_left_idx));
        }*/

        if(directories.empty()){
            ans+="/";
            return ans;
        }
        
        while(!directories.empty()){
            ans+="/";
            ans+=directories.front();
            directories.pop_front();
        }
        return ans;
    }
};