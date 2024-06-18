class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>freq;
        for(int i=0;i<changed.size();i++){
            freq[changed[i]]++;
        }
        vector<int>ans;
        for(auto iter=freq.begin();iter!=freq.end();iter++){
            if(iter->second!=0){
                if(iter->first==0){
                    if(iter->second%2!=0){
                        return {};
                    }
                    else{
                        for(int i=0;i<iter->second/2;i++){
                            ans.push_back(iter->first);
                        }
                        iter->second=0;
                    }
                }
                else{
                    if(freq.find(2*iter->first)==freq.end() || freq[2*iter->first]<iter->second){
                        return {};
                    }
                    else{
                        for(int i=0;i<iter->second;i++){
                            ans.push_back(iter->first);
                        }
                        freq[2*iter->first]-=iter->second;
                        iter->second=0;
                    }
                }
            }
        }
        return ans;
    }
};