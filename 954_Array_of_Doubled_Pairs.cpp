class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int>freq_pos,freq_neg;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                freq_pos[arr[i]]++;
            }
            else{
                freq_neg[arr[i]]++;
            }
        }
        for(auto iter=freq_pos.begin();iter!=freq_pos.end();iter++){
            if(iter->second!=0){
                if(iter->first==0){
                    if(iter->second%2!=0){
                        return false;
                    }
                    else{
                        iter->second=0;
                    }
                }
                else{
                    if(freq_pos.find(2*iter->first)==freq_pos.end() || freq_pos[2*iter->first]<iter->second){
                        return false;
                    }
                    else{
                        freq_pos[2*iter->first]-=iter->second;
                        iter->second=0;
                    }
                }
            }
        }
        for(auto iter=freq_neg.rbegin();iter!=freq_neg.rend();iter++){
            if(iter->second!=0){
                if(freq_neg.find(iter->first*2)==freq_neg.end() || freq_neg[2*iter->first]<iter->second){
                    return false;
                }
                else{
                    freq_neg[2*iter->first]-=iter->second;
                    iter->second=0;
                }
            }
        }
        return true;
    }
};