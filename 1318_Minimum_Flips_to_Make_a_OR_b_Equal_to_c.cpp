class Solution {
public:
    int minFlips(int a, int b, int c) {
        vector<int> bit_a,bit_b,bit_c;
        while(a>0){
            bit_a.push_back(a%2);
            a=a/2;
        }
        while(b>0){
            bit_b.push_back(b%2);
            b=b/2;
        }
        while(c>0){
            bit_c.push_back(c%2);
            c=c/2;
        }
        int len_a=bit_a.size(),len_b=bit_b.size(),len_c=bit_c.size();
        int len=max(len_a,max(len_b,len_c));
        for(int i=len_a;i<len;i++){
            bit_a.push_back(0);
        }
        for(int i=len_b;i<len;i++){
            bit_b.push_back(0);
        }
        for(int i=len_c;i<len;i++){
            bit_c.push_back(0);
        }
        int ans=0;
        for(int i=0;i<len;i++){
            if(bit_c[i]==0){
                if(bit_a[i]==1)++ans;
                if(bit_b[i]==1)++ans;
            }
            else{
                if(bit_a[i]==0 && bit_b[i]==0)++ans;
            }
        }
        return ans;
    }
};