class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,int>idx;
        unordered_map<int,unordered_set<int>> mp;
        for(int i=0;i<stones.size();i++){
            idx[stones[i]]=i;
        }
        mp[0].insert(0);
        for(int i=0;i<stones.size();i++){
            unordered_set<int>::iterator iter;
            for(iter=mp[i].begin();iter!=mp[i].end();iter++){
                for(int j=max(1,*iter-1);j<=*iter+1;j++){
                    if(idx.find(stones[i]+j)!=idx.end()){
                        mp[idx[stones[i]+j]].insert(j);
                    }
                }
            }
        }
        return (mp[stones.size()-1].size()!=0);
    }
};