class Solution {
public:
    int partition(vector<pair<pair<int,int>,int>>& v,int low,int high){
        int pivot=v[high].first.first;
        int i=low-1;
        for(int j=low;j<high;j++){
            if(v[j].first.first<pivot){
                i++;
                pair<pair<int,int>,int>tmp=v[j];
                v[j]=v[i];
                v[i]=tmp;
            }
        }
        i++;
        pair<pair<int,int>,int>tmp=v[high];
        v[high]=v[i];
        v[i]=tmp;
        return i;
    }
    void qsort(vector<pair<pair<int,int>,int>>& v,int low,int high){
        if(low<=high){
            int p=partition(v,low,high);
            qsort(v,low,p-1);
            qsort(v,p+1,high);
        }
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<pair<int,int>,int>>v;
        vector<int> ans(intervals.size());
        for(int i=0;i<intervals.size();i++){
            v.push_back({{intervals[i][0],intervals[i][1]},i});
        }
        qsort(v,0,v.size()-1);
        for(int i=0;i<v.size();i++){
            int j=i;
            while(j<v.size() && v[j].first.first<v[i].first.second){
                j++;
            }
            if(j>=v.size()){
                ans[v[i].second]=-1;
            }
            else{
                ans[v[i].second]=v[j].second;
            }
        }
        return ans;
    }
};