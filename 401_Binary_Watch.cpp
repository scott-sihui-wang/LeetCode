class Solution {
public:
    void genVal(int cap,int bound,int idx,int Ondigits,int turnedOn,int sum,vector<int>& sol){
        if(turnedOn-Ondigits>cap-idx)return;
        if(idx<cap && Ondigits<turnedOn){
            genVal(cap,bound,idx+1,Ondigits+1,turnedOn,sum+(1<<(cap-1-idx)),sol);
            genVal(cap,bound,idx+1,Ondigits,turnedOn,sum,sol);
        }
        if(Ondigits==turnedOn){
            if(sum<bound){
                sol.push_back(sum);
            }
            return;
        }   
    }
    string numToH(int n){
        if(n==0)return string("0");
        string ans("");
        while(n>0){
            ans=string(1,n%10+'0')+ans;
            n=n/10;
        }
        return ans;
    }
    string numToM(int n){
        if(n<10)return string("0")+string(1,'0'+n);
        string ans("");
        while(n>0){
            ans=string(1,n%10+'0')+ans;
            n=n/10;
        }
        return ans;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int i=0;i<=turnedOn;i++){
            vector<int>H;
            vector<int>M;
            genVal(4,12,0,0,i,0,H);
            genVal(6,60,0,0,turnedOn-i,0,M);
            for(int j=0;j<H.size();j++){
                for(int k=0;k<M.size();k++){
                    ans.push_back(numToH(H[j])+":"+numToM(M[k]));
                }
            }
        }
        return ans;
    }
};