class Solution {
public:
    int numLeadingOnes(int idx,vector<vector<int>>& bits){
        int cnt=0;
        int i=0;
        while(i<8 && bits[idx][i]!=0){
            cnt++;
            i++;
        }
        return cnt;
    }
    bool isValid(int start,vector<vector<int>>& bits){
        if(start==bits.size())return true;
        if(start>bits.size())return false;
        int num=numLeadingOnes(start,bits);
        if(num==0){
            return isValid(start+1,bits);
        }
        else if(num==2){
            if(start+1<bits.size() && numLeadingOnes(start+1,bits)==1){
                return isValid(start+2,bits);
            }
            else{
                return false;
            }
        }
        else if(num==3){
            if(start+1<bits.size() && numLeadingOnes(start+1,bits)==1 && start+2<bits.size() && numLeadingOnes(start+2,bits)==1){
                return isValid(start+3,bits);
            }
            else{
                return false;
            }
        }
        else if(num==4){
            if(start+1<bits.size() && numLeadingOnes(start+1,bits)==1 && start+2<bits.size() && numLeadingOnes(start+2,bits)==1 && start+3<bits.size() && numLeadingOnes(start+3,bits)==1){
                return isValid(start+4,bits);
            }
            else{
                return false;
            }
        }
        return false;
    }
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        vector<vector<int>>bits(n,vector<int>(8,0));
        for(int i=0;i<n;i++){
            int val=data[i];
            for(int j=7;j>=0;j--){
                if(val==0)break;
                bits[i][j]=val%2;
                val=val/2;
            }
        }
        return isValid(0,bits);
    }
};