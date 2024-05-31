class MyCalendar {
public:
    list<pair<int,int>>records;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(records.size()==0){
            records.push_back({start,end});
            return true;
        }
        else{
            auto iter=records.begin();
            while(iter!=records.end() && iter->first<start){
                iter++;
            }
            if(iter==records.begin()){
                if(end<=iter->first){
                    records.insert(iter,{start,end});
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                auto prev=--iter;
                ++iter;
                if((iter==records.end() || end<=iter->first) && start>=prev->second){
                    records.insert(iter,{start,end});
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */