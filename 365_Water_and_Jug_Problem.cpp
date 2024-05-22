class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        queue<pair<int,int>>q;
        set<pair<int,int>>s;
        q.push({0,0});
        s.insert({0,0});
        while(!q.empty()){
            pair<int,int>elem=q.front();
            if(elem.first+elem.second==target)return true;
            q.pop();
            if(elem.first>=0 && elem.first<x){
                if(s.find({x,elem.second})==s.end()){
                    q.push({x,elem.second});
                    s.insert({x,elem.second});
                }
            }
            if(elem.second>=0 && elem.second<y){
                if(s.find({elem.first,y})==s.end()){
                    q.push({elem.first,y});
                    s.insert({elem.first,y});
                }
            }
            if(elem.first>0){
                if(s.find({0,elem.second})==s.end()){
                    q.push({0,elem.second});
                    s.insert({0,elem.second});
                }
            }
            if(elem.second>0){
                if(s.find({elem.first,0})==s.end()){
                    q.push({elem.first,0});
                    s.insert({elem.first,0});
                }
            }
            int z=min(x-elem.first,elem.second);
            if(s.find({elem.first+z,elem.second-z})==s.end()){
                q.push({elem.first+z,elem.second-z});
                s.insert({elem.first+z,elem.second-z});
            }
            z=min(elem.first,y-elem.second);
            if(s.find({elem.first-z,elem.second+z})==s.end()){
                q.push({elem.first-z,elem.second+z});
                s.insert({elem.first-z,elem.second+z});
            }
        }
        return false;
    }
};