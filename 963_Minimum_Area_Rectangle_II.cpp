class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        map<pair<int,int>,set<pair<int,int>>>pts;
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                pts[{points[i][0],points[i][1]}].insert({points[j][0]-points[i][0],points[j][1]-points[i][1]});
                pts[{points[j][0],points[j][1]}].insert({points[i][0]-points[j][0],points[i][1]-points[j][1]});
            }
        }
        double ans=DBL_MAX;
        for(auto iter=pts.begin();iter!=pts.end();iter++){
            for(auto iter2=iter->second.begin();iter2!=iter->second.end();iter2++){
                for(auto iter3=iter2;iter3!=iter->second.end();iter3++){
                    if(iter2->first*iter3->first+iter2->second*iter3->second==0){
                        if(pts[{iter->first.first+iter2->first,iter->first.second+iter2->second}].find({iter3->first,iter3->second})!=pts[{iter->first.first+iter2->first,iter->first.second+iter2->second}].end()){
                            ans=min(ans,sqrt(iter2->first*iter2->first+iter2->second*iter2->second)*sqrt(iter3->first*iter3->first+iter3->second*iter3->second));
                        }
                    }
                }
            }
        }
        if(ans==DBL_MAX){
            return 0;
        }
        else{
            return ans;
        }
    }
};