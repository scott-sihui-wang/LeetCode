class RecentCounter {
public:
    int req[10000];
    int cnt,last;
    RecentCounter() {
        cnt=0;
        last=-1;
    }
    
    int ping(int t) {
        req[cnt++]=t;
        while(req[last+1]<t-3000){
            last++;
        }
        return cnt-last-1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */