class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> city;
        unordered_map<string,string>::iterator iter1,iter2;
        for(int i=0;i<paths.size();i++){
            city[paths[i][0]]=paths[i][1];
        }
        for(iter1=city.begin();iter1!=city.end();iter1++){
            iter2=city.find(iter1->second);
            if(iter2==city.end()){
                return iter1->second;
            }
        }
        return ("");
    }
};