class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> digits;
        int num=n;
        while(num>0){
            digits.push_back(num%10);
            num=num/10;
        }
        int sz=digits.size();
        int prop[10]={1,1,2,0,0,2,2,0,1,2};
        int val[10]={0,0,1,1,1,2,3,3,3,4};
        if(sz==1)return val[n];
        int ans=0;
        for(int i=1;i<digits[sz-1];i++){
            if(prop[i]==2){
                ans+=pow(7,sz-1);
            }
            else if(prop[i]==1){
                ans+=pow(7,sz-1)-pow(3,sz-1);
            }
        }
        for(int i=2;i<sz;i++){
            for(int j=1;j<=9;j++){
                if(prop[j]==2){
                    ans+=pow(7,i-1);
                }
                else if(prop[j]==1){
                    ans+=pow(7,i-1)-pow(3,i-1);
                }
            }
        }
        ans+=4;
        if(prop[digits[sz-1]]==2){
            int i=sz-2;
            while(i>=0){
                for(int j=0;j<digits[i];j++){
                    if(prop[j]!=0){
                        ans+=pow(7,i);
                    }
                }
                if(prop[digits[i]]==0){
                    break;
                }
                else{
                    if(i==0){
                        ans++;
                    }
                    i--;
                }
            }
        }
        else if(prop[digits[sz-1]]==1){
            bool isGood=false;
            int i=sz-2;
            while(i>=0){
                for(int j=0;j<digits[i];j++){
                    if(isGood){
                        if(prop[j]!=0){
                            ans+=pow(7,i);
                        }
                    }
                    else{
                        if(prop[j]==2){
                            ans+=pow(7,i);
                        }
                        else if(prop[j]==1){
                            ans+=pow(7,i)-pow(3,i);
                        }
                    }
                }
                if(prop[digits[i]]==0){
                    break;
                }
                else{
                    if(prop[digits[i]]==2){
                        isGood=true;
                    }
                    if(i==0 && (isGood || prop[digits[i]]==2)){
                        ans++;
                    }
                    i--;
                }
            }

        }
        return ans;
    }
};