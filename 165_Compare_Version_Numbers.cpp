class Solution {
public:
    int compareVersion(string version1, string version2) {
        int num;
        int i=0;
        vector<int> ver1,ver2;
        while(i<version1.size()){
            num=0;
            while(i<version1.size() && version1[i]!='.'){
                num=num*10+(version1[i]-'0');
                i++;
            }
            ver1.push_back(num);
            i++;
        }
        i=0;
        while(i<version2.size()){
            num=0;
            while(i<version2.size() && version2[i]!='.'){
                num=num*10+(version2[i]-'0');
                i++;
            }
            ver2.push_back(num);
            i++;
        }
        i=0;
        while(i<ver1.size()&&i<ver2.size()){
            if(ver1[i]<ver2[i]){
                return -1;
            }
            else if(ver1[i]>ver2[i]){
                return 1;
            }
            else{
                i++;
            }
        }
        for(;i<ver1.size();i++){
            if(ver1[i]>0)return 1;
        }
        for(;i<ver2.size();i++){
            if(ver2[i]>0)return -1;
        }
        return 0;
    }
};