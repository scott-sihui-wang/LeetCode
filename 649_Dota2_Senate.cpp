class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int> D,R;
        for(int i=0;i<n;i++){
            if(senate[i]=='D'){
                D.push(i);
            }
            else{
                R.push(i);
            }
        }
        while((!D.empty()) && (!R.empty())){
            if(D.front()<R.front()){
                D.push(n++);
            }
            else{
                R.push(n++);
            }
            D.pop();
            R.pop();
        }
        if(D.empty()){
            return string("Radiant");
        }
        else{
            return string("Dire");
        }
    }
};