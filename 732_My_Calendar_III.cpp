class MyCalendarThree {
public:
    vector<set<pair<int,int>>>v;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        int n=v.size();
        for(int i=n-1;i>=0;i--){
            for(auto iter=v[i].begin();iter!=v[i].end() && iter->first<endTime;iter++){
                if(startTime<iter->second){
                    if(i==n-1 && v.size()==n){
                        set<pair<int,int>>tmp;
                        tmp.insert({max(iter->first,startTime),min(iter->second,endTime)});
                        v.push_back(tmp);
                    }
                    else{
                        v[i+1].insert({max(iter->first,startTime),min(iter->second,endTime)});
                    }
                }
            }
        }
        if(n==0 && v.size()==0){
            set<pair<int,int>>tmp;
            tmp.insert({startTime,endTime});
            v.push_back(tmp);
        }
        else{
            v[0].insert({startTime,endTime});
        }
        return v.size();
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */