class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> dict1;
        unordered_map<string,int> dict2;
        unordered_map<string,int>::iterator iter1;
        unordered_map<string,int>::iterator iter2;
        for(int i=0;i<words1.size();i++){
            iter1=dict1.find(words1[i]);
            if(iter1==dict1.end()){
                dict1[words1[i]]=1;
            }
            else{
                iter1->second=iter1->second+1;
            }
        }
        for(int i=0;i<words2.size();i++){
            iter2=dict2.find(words2[i]);
            if(iter2==dict2.end()){
                dict2[words2[i]]=1;
            }
            else{
                iter2->second=iter2->second+1;
            }
        }
        int cnt=0;
        for(iter1=dict1.begin();iter1!=dict1.end();iter1++){
            if(iter1->second==1){
                iter2=dict2.find(iter1->first);
                if(iter2!=dict2.end() && iter2->second==1){
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};