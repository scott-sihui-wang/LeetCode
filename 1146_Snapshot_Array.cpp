class SnapshotArray {
public:
    unordered_map<int,int> arr;
    unordered_map<int,vector<pair<int,int>>>rec;
    bool modified;
    int snap_id;
    SnapshotArray(int length) {
        snap_id=0;
        modified=false;
    }
    
    void set(int index, int val) {
        if(!modified)modified=true;
        arr[index]=val;
    }
    
    int snap() {
        if(modified){
            for(unordered_map<int,int>::iterator iter=arr.begin();iter!=arr.end();iter++){
                rec[iter->first].push_back({snap_id,iter->second});
            }
            modified=false;
        }
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        if(rec.find(index)==rec.end()){
            return 0;
        }
        else{
            int begin=0,end=rec[index].size()-1;
            while(begin<=end){
                int mid=(begin+end)/2;
                if(rec[index][mid].first==snap_id){
                    return rec[index][mid].second;
                }
                else if(rec[index][mid].first<snap_id){
                    begin=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            if(end<0){
                return 0;
            }
            else{
                return rec[index][end].second;
            }
        }
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */