class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_map<int,int>nextIndex;//index, round
        int n=s2.size();
        int rep[n+1];//nums of reps of n2 for k scans of s1
        int ptr=0,cnt=0;
        for(int round=0;round<min(n1,n+1);round++){
            for(int i=0;i<s1.size();i++){
                if(s1[i]==s2[ptr]){
                    ptr++;
                }
                if(ptr==s2.size()){
                    ptr=0;
                    cnt++;
                }
            }
            rep[round]=cnt;
            if(round==n1-1){
                return cnt/n2;
            }
            if(nextIndex.find(ptr)==nextIndex.end()){
                nextIndex[ptr]=round;
            }
            else{
                int ans=rep[nextIndex[ptr]];
                ans+=(n1-1-nextIndex[ptr])/(round-nextIndex[ptr])*(cnt-rep[nextIndex[ptr]]);
                if((n1-1-nextIndex[ptr])%(round-nextIndex[ptr])!=0){
                    ans+=rep[nextIndex[ptr]+(n1-1-nextIndex[ptr])%(round-nextIndex[ptr])]-rep[nextIndex[ptr]];
                }
                return ans/n2;
            }
        }
        return -1;
    }
};